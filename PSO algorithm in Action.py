import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


# ---- B E N C H M A R K -- F U N C T I O N S ---- #
def paraboloid(vars, target= 1, ranges= [-5.12,5.12] ):#unimodal func: one global optimum solution
   X = vars[0]
   Y = vars[1]
   return X**2 + Y**2 + 1

# def zakharov(vars, dim= 2, target= 0, ranges=[-10,10]):#unimodal func: one global optimum solution
#         tmp1 = 0
#         tmp2 = 0
#         for i in range(dim):
#             tmp1 += vars[i]
#             tmp2 += (i+1)*vars[i]
#         return tmp1+np.power(1/2*tmp2,2)+np.power(1/2*tmp2,4)
     
def exp_func_task(vars, dim= 2, ranges=[-3,3]): #multimodal func(prof task): one global optimum solution
   X = vars[0]
   Y = vars[1]
   tmp1 = 3*(1-X)**2 * np.exp(-X**2 - (Y+1)**2)  - 10*((X/5) - X**3 - Y**5)
   tmp2 = np.exp(-X**2 - Y**2)
   tmp3 =  (-1/3) * np.exp(-(X+1)**2 - Y**2)
   return tmp1 * tmp2 * tmp3 

def rastrigin(vars, dim= 2, target= 0, ranges= [-5.12,5.12]): #mutlimodal fun: one global optimum solution
   n = len(vars)
   return 10*n + sum([xi**2 - 10*np.cos(2*np.pi*xi) for xi in vars])

# def schwefel(vars, dim: int= 2, target= -418.9829, ranges= [-500,500]): #mutlimodal func: one global optimum solution
#         tmp = 0
#         for i in range(dim):
#             tmp += vars[i]*np.sin(np.sqrt(np.absolute(vars[i])))
#         return -tmp
     
def shuberts(vars, dim= 2, target= -186.7309, range=[-10,10]): #mutlimodal func: Multiple global optimal solutions
        n = 5
        tmp1 = 0
        tmp2 = 0
        for i in range(n):
            tmp1 += (i+1)*np.cos((i+1)+(i+2)*vars[0])
            tmp2 += (i+1)*np.cos((i+1)+(i+2)*vars[1])
        return tmp1*tmp2
# ---- B E N C H M A R K -- F U N C T I O N S ---- #



def plot3D(solutionsX: np.ndarray, solutionsY: np.ndarray, solutionsZ: np.ndarray, refEq: callable= rastrigin, showTime = 1.5, rotate_deg1 = 90, rotate_deg2=-90, ticksXY = 3, plotRef = False, res= [-3,3,100]):
   '''
   # if `showTime == -1` :  play plot for inf. time (until user manually closes code/window)
   ---
   ## `solutionZ` are the **fitness** values calculated via the cost function e.g.(paraboloid)
   '''
   # Create a meshgrid for visualization
   x = np.linspace(res[0], res[1], res[2]) 
   y = np.linspace(res[0], res[1], res[2])
   X, Y = np.meshgrid(x, y)
   Z = refEq([X, Y])
   
   # Create a 3D plot of the Rastrigin function
   fig = plt.figure()
   ax: plt.Axes | Axes3D = fig.add_subplot(111, projection='3d')
   
   #plot the reference: also plot wire frame and contour are good
   if plotRef:
      ax.plot_surface(X, Y, Z, cmap='viridis', alpha=0.25)
   
   ax.set_xlabel('x')
   ax.set_ylabel('y')
   ax.set_zlabel('z (fitness)')
   
   # Plot the solution/s found by the PSO algorithm
   # if refEq == rastrigin or refEq == paraboloid:
   ax.set_xlim((-ticksXY, ticksXY) )
   ax.set_ylim((-ticksXY, ticksXY) )
   ax.set_xticks( np.linspace(-ticksXY, ticksXY , 5) )
   ax.set_yticks( np.linspace(-ticksXY, ticksXY , 5) )
   ax.scatter3D(solutionsX, solutionsY, solutionsZ,  color='Red')
   
   # Rotate the plot by setting the viewing angle
   ax.view_init(elev=rotate_deg1, azim=rotate_deg2)
   
   # Matplotlib by default stops all python script until you close the GUI window
   if showTime != -1: 
      plt.show(block= False)
      plt.pause(showTime)
      plt.close()
   else:
      plt.show()

def isArrived(_tolerance, gBest, _target ) -> bool:
   return False if abs(gBest - _target) <= _tolerance else True

def isStagnated(nearZero, _currentV, stags, particlesNo) -> bool:
   '''
   This is faster than checking each particle velocity against the tolerance
   '''
   #slower
   isNearZero = np.all(_currentV <= nearZero)
   return isNearZero

   
   
   #faster(less accurate)
   #return True if np.sum(np.abs(_currentV)) <= nearZero else False


# Define the PSO algorithm
def pso(cost_func, constraintsXY, dim=2, num_particles=100, max_iter=30, w=0.5, c1=1, c2=1.5, tolerance= 1e-6, searchingMax= False, target= None, stagnationLimit= 4, showTime = 1.5):
   # Initialize particles and velocities
   particles = np.random.uniform(constraintsXY[0], constraintsXY[1], (num_particles, dim)) if constraintsXY[1] < 5.12 else  np.random.uniform(-5.12, 5.12, (num_particles, dim)) 
   velocities = np.zeros((num_particles, dim))
   
   # zeroV = np.zeros((num_particles, dim)) #as ref to check stagnation

   # Initialize the best positions and fitness values
   best_positions = np.copy(particles)
   best_fitness = np.array([cost_func(p) for p in particles])
   swarm_best_position = best_positions[np.argmax(best_fitness) if searchingMax else np.argmin(best_fitness)]
   swarm_best_fitness = np.max(best_fitness) if searchingMax else np.min(best_fitness)
   
   stagCount = 0
   # Iterate through the specified number of iterations, updating the velocity and position of each particle at each iteration
   for i in range(max_iter):
      # Update velocities
      r1 = np.random.uniform(0, 1, (num_particles, dim))
      r2 = np.random.uniform(0, 1, (num_particles, dim))
      
      velocities = w * velocities + c1 * r1 * (best_positions - particles) + c2 * r2 * (swarm_best_position - particles)

      # Update positions
      particles += velocities

      # Evaluate fitness of each particle
      fitness_values = np.array([cost_func(p) for p in particles])

      # Update best positions and fitness values
      improved_indices = np.where(fitness_values > best_fitness) if searchingMax else np.where(fitness_values < best_fitness)
      best_positions[improved_indices] = particles[improved_indices]
      best_fitness[improved_indices] = fitness_values[improved_indices]
      
      DoesNeedUpdate = (np.max(fitness_values) > swarm_best_fitness) if searchingMax else (np.min(fitness_values) < swarm_best_fitness) 
      if DoesNeedUpdate:
            swarm_best_position = particles[np.argmax(fitness_values) if searchingMax else np.argmin(fitness_values)]
            swarm_best_fitness = np.max(fitness_values) if searchingMax else np.min(fitness_values)
      
      
      # -------------- T E R M I N A T I O N -- C H E C K E R S -------------- #
      if target is not None and isArrived(tolerance, swarm_best_fitness, target):
         print("\n\n \t ~Arrived to The Optimal value! Terminating~")
         return swarm_best_position, swarm_best_fitness
      
      stagCount = stagCount + 1 if isStagnated(tolerance * 1e2, velocities, stagCount, particlesNo= particles) else 0
      if stagCount >= stagnationLimit :
         print("\n\n \t\t ~Stagnation Detected! Terminating~")
         return swarm_best_position, swarm_best_fitness
      # -------------- T E R M I N A T I O N -- C H E C K E R S -------------- #
         
      
      # Print the solution and fitness value
      print(f'----I T E R A T I O N : ({i})----')
      print('Current best Solution:', swarm_best_position)
      print('Current Fitness:', swarm_best_fitness)
      
      # Plot current best
      plot3D(best_positions[:,0], best_positions[:,1], best_fitness, refEq= cost_func, plotRef=True, showTime= showTime)

   # Return the best solution found by the PSO algorithm
   return swarm_best_position, swarm_best_fitness


if __name__ == "__main__":
   # Define Your Custom parameters here:
   constraintsXY = [-3,3]
   dim = 2
   particles_no = 100
   used_eq: callable = exp_func_task

   # Run the PSO algorithm on the Rastrigin function
   solution, fitness = pso(used_eq, constraintsXY, dim=dim, num_particles= particles_no, searchingMax=True, max_iter=40, showTime= 1.5)
   
   print(f'\n\n\n ---- F I N A L E ----')
   print('Solution:', solution)
   print('Fitness:', fitness)
   print('---- ---- ---- ---- ---- ----')
   
   plot3D(solution[0], solution[1], fitness, showTime= -1, plotRef= True, rotate_deg1=40, rotate_deg2=20, refEq= used_eq)



