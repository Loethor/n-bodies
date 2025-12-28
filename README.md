# N-Body Simulation

This project simulates the gravitational interaction of multiple bodies (n-body problem) using C++20. It features modular design, unit tests, and CSV output for easy visualization.

## Features
- Modular C++20 codebase
- Euler integrator (easily extensible)
- Google Test integration
- CSV output for visualization
- Configurable initial conditions via text files

## Build Instructions

### Prerequisites
- CMake >= 3.20
- C++20 compatible compiler (e.g., g++ 10+)
- Make

### Build and Run
```sh
make           # Build the project
make run       # Run the simulation (outputs to terminal)
make test      # Run all unit tests
```

## Project Structure
- `src/`         - Source files
- `include/`     - Header files
- `tests/`       - Unit tests (Google Test)
- `data/`        - Example configuration files
- `output.csv`   - Example output file (generated)
- `scripts/`     - Python scripts for visualization

## Configuration Files
Configuration files (e.g., `data/earth_moon.txt`) are space-separated text files:
```
# name mass x y z vx vy vz
Earth 5.972e24 0 0 0 0 0 0
Moon 7.348e22 384400000 0 0 0 1022 0
```

## Output
Simulation results can be written to a CSV file for visualization. Each row contains:
```
time,body_name,x,y,z,vx,vy,vz
```

## Visualization

Example animation:

![Earth-Moon Simulation](output/earth_moon.gif)

df = pd.read_csv('output.csv')

### Python Visualization
To visualize the simulation output, use the provided Python script:

```sh
cd scripts
python3 -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
python plot_output.py ../output/earth_moon.csv
```
This will plot the trajectories of all bodies using matplotlib.

You can also use Excel or any plotting tool to visualize `output.csv`.

## License
MIT
