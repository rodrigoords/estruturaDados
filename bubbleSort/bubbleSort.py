import random

ARRAY_SIZE = 20
hasAlter = True
bubbleIteration = [None]*ARRAY_SIZE


def setUp():
    random.seed()
    for x in range (0,ARRAY_SIZE):
        bubbleIteration[x] = random.randint(0,100)

def bubbleSort(bubbleIteration):
    global hasAlter
    while hasAlter:
        hasAlter = False
        for x in range(0,len(bubbleIteration)-1):
            if bubbleIteration[x] > bubbleIteration[x+1]:
                alterValues(bubbleIteration, x, x+1)


def alterValues(bubbleIteration, indexA, indexB):
    global hasAlter
    aux = bubbleIteration[indexA]
    bubbleIteration[indexA] = bubbleIteration[indexB]
    bubbleIteration[indexB] = aux
    hasAlter = True


setUp()
print "=========== List ==========="
print bubbleIteration
print "=========== executing Bubble Sort ==========="
bubbleSort(bubbleIteration)
print "=========== Result after Bubble Sort ==========="
print bubbleIteration
