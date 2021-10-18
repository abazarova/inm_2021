import numpy as np

#solve (4x^2 - 10x + 6 = 0)

x = 0 # Initial Guess
for iteration in range(1, 101): # Setting iterations to 100
    x_new = (4*x**2 + 6)/10      # Finding the new value
    if abs(x_new - x) < 0.000001: # degree of accuracy condition
        break
    x = x_new                    # Assigns the value of x_new to x
print('The root : %0.5f' % x_new)
print('The number of iterations : %d' % iteration)
x = 1.5     # Initial Guess
for iteration in range(1,101):# Setting iterations to 100
    x_new = (4*x**2 + 6)/10   # Finding the new value
    if abs(x_new - x) < 0.000001: # degree of accuracy condition
        break
    x = x_new       # Assigns the value of x_new to x
print('The root : %0.5f' % x_new)
print('The number of iterations : %d' % iteration)
exit()
