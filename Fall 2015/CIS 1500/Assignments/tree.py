#!/bin/python

import sys
import os


# Complete the function below.

class Node(object):
def __init__(self, data):
    self.data = data
    self.children = []

def add_child(self, obj):
    self.children.append(obj)

def  SExpression(nodes):
    #get the position of all the letters following (

    n = nodes.index('(')+1;
    o = n+2
    

f = open(os.environ['OUTPUT_PATH'], 'w')


_nodes = raw_input()

res = SExpression(_nodes);
f.write(res + "\n")

f.close()
