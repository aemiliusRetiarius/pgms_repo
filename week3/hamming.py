import numpy as np
from pgmpy.factors.discrete import DiscreteFactor

disc_bit_4 = DiscreteFactor(['b0', 'b1', 'b2', 'b4'], [2, 2, 2, 2], [1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1])
disc_bit_5 = DiscreteFactor(['b0', 'b2', 'b3', 'b5'], [2, 2, 2, 2], [1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1])
disc_bit_6 = DiscreteFactor(['b0', 'b1', 'b3', 'b6'], [2, 2, 2, 2], [1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1])

print(disc_bit_4)