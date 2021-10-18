import numpy as np

#solve Ax = b where A = [[1, 2], [3, 4]], b = [1, 1]
A = np.array([[1, 2], [3, 3]])
b = np.ones((2, 1))
B = np.identity(2)
x = np.zeros((2, 1)) # Initial Guess
tau = 0.1
for iteration in range(1, 101): # Setting iterations to 100
    x_new = B @ x + tau * b      # Finding the new value
    if np.linalg.norm(x_new - x) < 0.000001: # degree of accuracy condition
        break
    x = x_new                    # Assigns the value of x_new to x
print('The root :',  x_new)
print('The number of iterations : %d' % iteration)
exit()
