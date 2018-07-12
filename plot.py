import numpy as np
import matplotlib.pyplot as plt

e=np.genfromtxt("dat.txt")
xm=e[:,0]
um=e[:,1]

x=xm[100:]
u=um[100:]

plt.figure()
plt.plot(x[9000:12000],u[9000:12000])
plt.show()
