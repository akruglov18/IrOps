import torch
import numpy as np
import os

t = torch.IntTensor([[1, 2, 3], [4, 5, 6]])

buildDir = os.environ.get('BUILD_DIR')

np.savetxt(buildDir + 'tests_ref/tests.txt', t.numpy(), fmt="%d")
