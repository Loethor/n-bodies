import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import sys
import os
import numpy as np

if len(sys.argv) > 1:
    filename = sys.argv[1]
else:
    filename = '../output/earth_moon.csv'

# Determine output GIF path in output/ folder
base = os.path.splitext(os.path.basename(filename))[0]
gif_path = os.path.join(os.path.dirname(filename), base + '.gif')

df = pd.read_csv(filename)
bodies = df['body_name'].unique()
steps = df['time'].unique()

# Only animate every 10th frame
frame_indices = list(range(0, len(steps), 10))
if frame_indices[-1] != len(steps) - 1:
    frame_indices.append(len(steps) - 1)

fig, ax = plt.subplots()
colors = plt.colormaps.get_cmap('tab10')
# Get radius for each body (default to 1e6 if missing)
body_radius = {row['body_name']: row['radius'] if 'radius' in row else 1e6 for _, row in df.drop_duplicates('body_name').iterrows()}
# Use log scale for marker size, ensure minimum size
lines = {name: ax.plot([], [], 'o', label=name, color=colors(i / max(1, len(bodies) - 1)), markersize=5)[0] for i, name in enumerate(bodies)}
trails = {name: ax.plot([], [], '-', color=colors(i / max(1, len(bodies) - 1)), alpha=0.5)[0] for i, name in enumerate(bodies)}

ax.set_xlabel('x (m)')
ax.set_ylabel('y (m)')
ax.set_title('N-Body Simulation Animation')
ax.legend(loc='upper right')
ax.set_aspect('equal', adjustable='box')

# Set axis limits based on data
margin = 0.1 * max(df['x'].max() - df['x'].min(), df['y'].max() - df['y'].min())
ax.set_xlim(df['x'].min() - margin, df['x'].max() + margin)
ax.set_ylim(df['y'].min() - margin, df['y'].max() + margin)

# Store trails
history = {name: {'x': [], 'y': []} for name in bodies}

def init():
    for name in bodies:
        lines[name].set_data([], [])
        trails[name].set_data([], [])
    return list(lines.values()) + list(trails.values())

def animate(i):
    t = steps[frame_indices[i]]
    frame = df[df['time'] == t]
    for name in bodies:
        bx = frame[frame['body_name'] == name]['x'].values
        by = frame[frame['body_name'] == name]['y'].values
        if len(bx) > 0 and len(by) > 0:
            lines[name].set_data([bx[0]], [by[0]])
            history[name]['x'].append(bx[0])
            history[name]['y'].append(by[0])
            trails[name].set_data(history[name]['x'], history[name]['y'])
    hour = float(t) / 3600
    ax.set_title(f'N-Body Simulation Animation\nHour: {hour:.1f}')
    percent = int(100 * (i + 1) / len(frame_indices))
    if percent % 5 == 0 and (i + 1 == len(frame_indices) or (100 * i // len(frame_indices)) % 5 != 0):
        print(f"Rendering: {percent}% ({i+1}/{len(frame_indices)}) (Hour: {hour:.1f})")
    return list(lines.values()) + list(trails.values())

ani = animation.FuncAnimation(fig, animate, frames=len(frame_indices), init_func=init, blit=True, interval=100, repeat=False)

# Save animation as GIF in output folder
ani.save(gif_path, writer=animation.PillowWriter(fps=60))

# Uncomment the next line if you have X11 forwarding or a GUI:
# plt.show()
