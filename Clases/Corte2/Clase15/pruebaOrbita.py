import gravedad
import gravedadCy
import time

#cython: language_level=3

#Se inicializa el planeta para python
tierra = gravedad.Planet()
tierra.x = 100e3
tierra.y = 300e3
tierra.z = 300e3
tierra.vx = 2e3
tierra.vy = 29.87e3
tierra.vz = 0.034e3


tierra.m = 5.9736e24


tierraCy = gravedadCy.Planet()
tierraCy.x = 100e3
tierraCy.y = 300e3
tierraCy.z = 300e3
tierraCy.vx = 2e3
tierraCy.vy = 29.87e3
tierraCy.vz = 0.034e3

tierraCy.m = 5.9736e24


time_span, n_steps = 600, 4000000

initTime = time.time()
gravedad.step_time(tierra,time_span,n_steps)
endTime = time.time()
totalTime = endTime - initTime
print("EL tiempo total en python es ",totalTime)


initTimeCy = time.time()
gravedadCy.step_time(tierraCy,time_span,n_steps)
endTimeCy = time.time()
totalTimeCy = endTimeCy - initTimeCy
print("EL tiempo total en cython es ",totalTimeCy)

speed_up = endTime/endTimeCy
print("Speed Up:",speed_up)
speed_up=endTime