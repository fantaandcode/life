from time import time
from math import floor

class CodeDrop:
    def __init__(self, x, y, yMax, speed, persistence):
        self.x = x
        self.origin = y
        self.min = y
        self.max = y
        self.yMax = yMax  # the greatest position on the Y axis that a drop can be
        self.speed = speed
        self.persistence = persistence # the time that the point of origin of the drop will take to start falling down
        self.birth = time()

    def getX(self):
        return self.x

    def getMin(self):
        return self.min

    def getMax(self):
        return self.max

    def update(self):
        """function to be called between each frame to determine the new position of the drop"""
        lasted = time() - self.birth
        offset = lasted - self.persistence
        if offset < 0:
            offset = 0
        self.min = floor(offset * self.speed + self.origin)
        self.max = floor(lasted * self.speed + self.origin)
        if self.min > self.yMax:
            self.min = self.yMax
        if self.max > self.yMax:
            self.max = self.yMax