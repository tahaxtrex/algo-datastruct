import matplotlib.pyplot as plt
import numpy as np

# Data from the table
sizes = np.array([10, 60, 110, 160, 210, 260, 310, 360, 410, 460])
worst_case = np.array([1.2, 15.2, 37.5, 78.2, 132.6, 162.1, 239.2, 361.3, 439.1, 517.9])
best_case = np.array([0.7, 11.2, 27, 54.3, 91.5, 137.6, 193, 259, 333.4, 415.7])
average_case = np.array([0.9, 14.26, 36.5, 69.56, 110.62, 163.58, 228.62, 304.48, 380.74, 480.98])

# Create the plot
plt.figure(figsize=(10, 6))
plt.plot(sizes, worst_case, marker='o', linestyle='-', color='r', label="Worst Case (O(n²))")
plt.plot(sizes, best_case, marker='s', linestyle='-', color='g', label="Best Case (O(n²))")
plt.plot(sizes, average_case, marker='d', linestyle='-', color='b', label="Average Case (O(n²))")

# Labels and title
plt.xlabel("Input Size (n)")
plt.ylabel("Execution Time (microseconds)")
plt.title("Selection Sort Complexity Analysis")
plt.legend()
plt.grid(True)

# Show the plot
plt.show()
