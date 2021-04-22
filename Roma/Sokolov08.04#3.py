import numpy as np
import matplotlib.pyplot as plt
from time import sleep
import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
dac=[26,19,13,6,5,11,9,10]
GPIO.setup(dac, GPIO.OUT)

print("Введите time: ")
time = int(input())
print("Введите frequency: ")
frequency = float(input())
print("Введите samplingFrequency: ")
samplingFrequency = float(input())

def decToBinList(n):
    N = 7
    p = 0
    X =[]
    while N > 0:
        p = int(n/2**N)
        if p == 1:
            X.append(1)
            n-=2**N
        else:
            X.append(0)
        N-=1
    X.append(n)
    return X

def num2dac(value):
    D = dac
    N = [0,0,0,0,0,0,0,0]
    N = decToBinList(value)
    for i in range (0,8):
        GPIO.output(D[i],N[i])
    time.sleep(1)


time_plot = np.arange(0, time, 1/samplingFrequency)
amplitude = np.sin(2*3.14*time_plot + 1)

#for i in time_plot:
#    num2dac(amplitude[i] * 255)

plt.plot(time_plot, amplitude)
plt.title('Синус')
plt.xlabel('Время')
plt.ylabel('Амплитуда sin(time)')
plt.show() 


GPIO.output(dac,0)
GPIO.cleanup()