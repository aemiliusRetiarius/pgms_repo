import numpy as np
from pgmpy.factors.discrete import DiscreteFactor

disc_bit_4 = DiscreteFactor(['b0', 'b1', 'b2', 'b4'], [2, 2, 2, 2], [1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1])
disc_bit_5 = DiscreteFactor(['b0', 'b2', 'b3', 'b5'], [2, 2, 2, 2], [1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1])
disc_bit_6 = DiscreteFactor(['b0', 'b1', 'b3', 'b6'], [2, 2, 2, 2], [1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1])

disc_joint = (disc_bit_4.product(disc_bit_5, inplace=False)).product(disc_bit_6, inplace=False)
disc_joint.normalize()

print(disc_joint)

disc_joint.reduce([('b0', 1), ('b1', 0), ('b2', 1), ('b3', 0)])
disc_joint.normalize()

print(disc_joint)