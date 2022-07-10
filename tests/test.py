import torch
import numpy as np
import os

t = torch.tensor([[1, 2, 3], [4, 5, 6]])

print(t)

basedir = os.path.abspath(__file__)

np.savetxt(basedir + '\\build\\test_ref\\test.txt', t.numpy())
