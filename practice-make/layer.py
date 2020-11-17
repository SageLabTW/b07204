import numpy as np

class layer:
    
    def __init__(self, W, b):
        self.W = W
        self.b = b
        self.m, self.n = W.shape
    
    def feedforward(self, data):
        return np.dot(data, self.W) + self.b
