from math import sqrt

class Planet(object):
	def __init__(self):
	# Alguna posición 
		self.x = 1.0
		self.y = 0.0
		self.z = 0.0
		self.vx = 0.0
		self.vy = 0.5
		self.vz = 0.0
	# Masa
		self.m = 1.0

def single_step(planet, dt):
	""" Se hace un paso  en el tiempo """

	#Calculo de la fuerza: gravedad sobre el origen
	distancia = sqrt(planet.x**2+planet.y**2+planet.z**2)
	Fx = -planet.x/distancia**3
	Fy = -planet.y/distancia**3
	Fz = -planet.z/distancia**3

	# Paso del tiempo de posicion, de acuero a la v
	planet.x += dt*planet.vx
	planet.y += dt*planet.vy
	planet.z += dt*planet.vz

	# Paso del tiempo de velocidad, de acuero a la f y m
	planet.vx += dt*Fx/planet.m
	planet.vy += dt*Fy/planet.m
	planet.vz += dt*Fz/planet.m
			
def step_time(planet, time_span, n_steps):
	dt = time_span/n_steps

	for j in range(n_steps):
		single_step(planet, dt)		


