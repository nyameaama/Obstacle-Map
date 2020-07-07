from graphics import *
from generateSensorReadings import *

#0 - 450
#250 - 500

def main():
    win = GraphWin("Visualize Main", 500, 500)
    #c = Circle(Point(50,50), 1)
    #Get sensor reading
    bearing = returnBearing()
    value = returnDistValue()
    coordinates = plot(bearing,value)
    x = Circle(Point(coordinates[0],coordinates[1]), 1)
    x.draw(win)
    win.getMouse() # pause for click in window win.close()


def plot(bearing,value):
    translatedValueforward = translate(value,0,450) #x axis
    y_axis = translate(bearing,0,90)
    points = [translatedValueforward,y_axis]
    return points

def translate(x,LB,UB):
    #R = (V - M1) * R2 / R1 + M2
    temp1 = 0
    translated_reading = 0
    R2 = (500 - 250)
    R1 = UB - LB
    temp1 = (x - (LB))
    translated_reading = temp1 * (R2 / R1) + 250
    return translated_reading


def pythagorasTheorem():
    #c^2 = a^2 + b^2
    c = 0

main()