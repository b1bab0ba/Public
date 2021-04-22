import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
leds=[24,25,8,7,12,16,20,21]
GPIO.setup(leds, GPIO.OUT)

def lightUp(ledNumber, period):
    GPIO.output(ledNumber,period)
    time.sleep(1)
    GPIO.output(ledNumber,0)


def blink(ledNumber, blinkCount, blinkPeriod):
    for j in range (0, blinkCount):
        GPIO.output(ledNumber,1)
        time.sleep(blinkPeriod)
        GPIO.output(ledNumber,0)
        time.sleep(blinkPeriod)

def runningLight(count, period):
    for j in range (0, count):
        for i in leds:
            GPIO.output(i,1)
            time.sleep(period)
            GPIO.output(i,0)
            time.sleep(period)

def runningDark(count, period):
    GPIO.output(leds,1)
    for j in range (0, count):
        for i in leds:
            GPIO.output(i,0)
            time.sleep(period)
            GPIO.output(i,1)
            time.sleep(period)
    GPIO.output(leds,0)

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

def lightNumber(number):
    D = [21,20,16,12,7,8,25,24]
    N = [0,0,0,0,0,0,0,0]
    N = decToBinList(number)
    j = 7
    for i in range (0,8):
        GPIO.output(D[i],N[i])
    time.sleep(0.5)
    
             
#def runningPatern(pattern, direction)
 #  lightNumber(pattern)
 #  time.sleep(20)
 #   while True

    
        


lightUp(20, 1)
#blink(25, 3, 0.5)
#runningLight(2, 0.1)
#runningDark(3, 0.1)
#lightNumber(5)


GPIO.output(leds,0)
GPIO.cleanup()