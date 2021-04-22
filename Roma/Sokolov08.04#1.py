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
    time.sleep(1)

    

while 1:
    print("Введите число: ")
    x = int(input())
    if x >= 0:
        num2dac(x)
        GPIO.output(dac,0)
    elif x == -1:
        GPIO.output(dac,0)
        GPIO.cleanup()
        exit(0)
    else:
        print("Введите другое число") 
      


GPIO.output(dac,0)
GPIO.cleanup()