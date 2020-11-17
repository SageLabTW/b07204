import numpy as np

class layer:
    
    def __init__(self, W, b):
        if W.shape[1] != b.shape[0]:
            raise Exception('Dimension error.')
        self.W, self.b = W, b
        self.m, self.n = W.shape
    
    def __str__(self):
        return 'W:\n%s\nsize: %s\nb:\n%s'%(self.W, (self.m, self.n), self.b)
    
    def activate(data):
        return 1 / (1 + np.exp(-data))
    
    def feedforward(self, data):
        return np.dot(data, self.W) + self.b

class neural_network:
    
    def __init__(self, layers):
        self.layers = layers
    
    def feedforward(self, data):
        for layer in self.layers:
            data = layer.feedforward(data)
        return data
    
    def __str__(self):
        return None
