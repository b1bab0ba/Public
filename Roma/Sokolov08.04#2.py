import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
dac=[26,19,13,6,5,11,9,10]
GPIO.setup(dac, GPIO.OUT)


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
    j = 7
    for i in range (0,8):
        GPIO.output(D[i],N[i])
    time.sleep(0.02)

print("Введите число повторений: ")
repetitionsNumber = int(input())
for i in range (0, repetitionsNumber):
    for j in range (0,255):
        num2dac(j)
    for j in range (0, 255):
        num2dac(255-j)
      


GPIO.output(dac,0)
GPIO.cleanup()