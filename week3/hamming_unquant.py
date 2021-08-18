import numpy as np
import math
from pgmpy.factors.discrete import DiscreteFactor

def normal(r, b):
    variance = 0.25
    u_0 = -1
    u_1 = 1
    if b == 0:
        sample = ( 1/math.sqrt(2*variance) ) * math.exp( -((r - u_0) ** 2) / (2 * variance) )
    else:
        sample = ( 1/math.sqrt(2*variance) ) * math.exp( -((r - u_1) ** 2) / (2 * variance) )
    return sample

disc_bit_4 = DiscreteFactor(['b0', 'b1', 'b2', 'b4'], [2, 2, 2, 2], [1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1])
disc_bit_5 = DiscreteFactor(['b0', 'b2', 'b3', 'b5'], [2, 2, 2, 2], [1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1])
disc_bit_6 = DiscreteFactor(['b0', 'b1', 'b3', 'b6'], [2, 2, 2, 2], [1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1])

disc_joint = (disc_bit_4.product(disc_bit_5, inplace=False)).product(disc_bit_6, inplace=False)
disc_joint.normalize()

#correct squence 1 0 1 0 0 0 1
r_0 = 1
r_1 = -1
r_2 = 1
r_3 = -1
r_4 = 0.01
r_5 = -1
r_6 = 1

disc_bit_r_0 = DiscreteFactor(['b0'], [2], [normal(r_0, 0), normal(r_0, 1)])
disc_bit_r_1 = DiscreteFactor(['b1'], [2], [normal(r_1, 0), normal(r_1, 1)])
disc_bit_r_2 = DiscreteFactor(['b2'], [2], [normal(r_2, 0), normal(r_2, 1)])
disc_bit_r_3 = DiscreteFactor(['b3'], [2], [normal(r_3, 0), normal(r_3, 1)])
disc_bit_r_4 = DiscreteFactor(['b4'], [2], [normal(r_4, 0), normal(r_4, 1)])
disc_bit_r_5 = DiscreteFactor(['b5'], [2], [normal(r_5, 0), normal(r_5, 1)])
disc_bit_r_6 = DiscreteFactor(['b6'], [2], [normal(r_6, 0), normal(r_6, 1)])

disc_bit_r_0.normalize()
disc_bit_r_1.normalize()
disc_bit_r_2.normalize()
disc_bit_r_3.normalize()
disc_bit_r_4.normalize()
disc_bit_r_5.normalize()
disc_bit_r_6.normalize()

print(disc_bit_r_0)

disc_joint.product(disc_bit_r_0)
disc_joint.product(disc_bit_r_1)
disc_joint.product(disc_bit_r_2)
disc_joint.product(disc_bit_r_3)
disc_joint.product(disc_bit_r_4)
disc_joint.product(disc_bit_r_5)
disc_joint.product(disc_bit_r_6)

disc_joint.normalize()

print(disc_joint)