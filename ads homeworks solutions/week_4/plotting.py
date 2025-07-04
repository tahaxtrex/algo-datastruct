import matplotlib.pyplot as plt
import numpy as np

# Data from the results
k_values = np.array([0, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000])
Worst_case = np.array([2.319, 0.2198, 0.1718, 0.1328, 0.3173, 0.1898, 0.2064, 0.1899, 0.1903, 0.2235])
AveregeCase = np.array([2.1339, 0.2934, 0.1796, 0.1554, 0.195, 0.0898, 0.0825, 0.1357, 0.0789, 0.0766])
best_case = np.array([1.7858, 0.2356, 0.2216, 0.1515, 0.1354, 0.0835, 0.0765, 0.0766, 0.0771, 0.081])

# Create the plot
plt.figure(figsize=(10, 6))
plt.plot(k_values, Worst_case, marker='o', linestyle='-', label="Worst Case", color='b')
plt.plot(k_values, AveregeCase, marker='s', linestyle='-', label="Average case Case", color='r')
plt.plot(k_values, best_case, marker='d', linestyle='-', label="Best Case", color='g')

# Labels and title
plt.xlabel("k values")
plt.ylabel("Execution Time (ms)")
plt.title("Execution Time vs. k for Different Cases")
plt.legend()
plt.grid(True)

# Show the plot
plt.show()
