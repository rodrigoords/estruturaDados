import random

ARRAY_SIZE = 20

class Bubble():
    hasAlter = True
    bubbleIteration = []

    def __init__(self, arraySize):
        self.bubbleIteration = [None]*arraySize
        random.seed()

    def setUp(self):
        for x in range (0,len(self.bubbleIteration)):
            self.bubbleIteration[x] = random.randint(0,100)

    def sort(self):
        while self.hasAlter:
            self.hasAlter = False
            for x in range(0,len(self.bubbleIteration)-1):
                if self.bubbleIteration[x] > self.bubbleIteration[x+1]:
                    self.alterValues(x, x+1)

    def alterValues(self, indexA, indexB):
        aux = self.bubbleIteration[indexA]
        self.bubbleIteration[indexA] = self.bubbleIteration[indexB]
        self.bubbleIteration[indexB] = aux
        self.hasAlter = True

    def getBubbleIteration(self):
        return self.bubbleIteration

bubble = Bubble(10)
bubble.setUp()
print "=========== List ==========="
print bubble.getBubbleIteration()
print "=========== executing Bubble Sort ==========="
bubble.sort()
print "=========== Result after Bubble Sort ==========="
print bubble.getBubbleIteration()
