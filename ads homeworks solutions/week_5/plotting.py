import matplotlib.pyplot as plt
import numpy as np

# Define the Fibonacci sequence indices
n_values = np.array([0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38])

# Define execution times for different methods
recursion_times = np.array([0.0001, 0, 0.0001, 0.0001, 0.0002, 0.0004, 0.0009, 0.0017, 0.004, 0.0104, 0.0271, 0.0794, 0.1931, 0.5114, 1.332, 3.4725, 9.1439, 26.459, 66.3652, 169.116])
iteration_times = np.array([0.0003, 0.00017, 0.00019, 0.0002, 0.0002, 0.0002, 0.0003, 0.0002, 0.0003, 0.0004, 0, 0.0006, 0.0005, 0.0005, 0.0005, 0.0006, 0.0007, 0.0007, 0.0013, 0.0014])
closed_times = np.array([0, 0, 0, 0, 0.0001, 0, 0, 0.0001, 0.0001, 0.0001, 0, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0002, 0.0001, 0.0002])
matrix_times = np.array([0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0002, 0.0002, 0.0002, 0.0002, 0.0002, 0.0002, 0.0002, 0.0002, 0.0002, 0.0002, 0.0002, 0.0002, 0.0002])

# Plot the data
plt.figure(figsize=(10, 6))
plt.plot(n_values, recursion_times, marker='o', linestyle='-', color='r', label="Recursion")
plt.plot(n_values, iteration_times, marker='s', linestyle='-', color='g', label="Iteration")
plt.plot(n_values, closed_times, marker='d', linestyle='-', color='b', label="Closed Form")
plt.plot(n_values, matrix_times, marker='x', linestyle='-', color='m', label="Matrix Exponentiation")

# Labels and title
plt.xlabel("n (Fibonacci index)")
plt.ylabel("Execution Time (ms)")
plt.title("Fibonacci Computation Time Comparison")
plt.yscale("log")  # Log scale for better visualization
plt.legend()
plt.grid(True)

# Show the plot
plt.show()
