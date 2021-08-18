import numpy as np
from pgmpy.factors.discrete import DiscreteFactor

disc_bit_4 = DiscreteFactor(['b0', 'b1', 'b2', 'b4'], [2, 2, 2, 2], [1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1])
disc_bit_5 = DiscreteFactor(['b0', 'b2', 'b3', 'b5'], [2, 2, 2, 2], [1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1])
disc_bit_6 = DiscreteFactor(['b0', 'b1', 'b3', 'b6'], [2, 2, 2, 2], [1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1])

disc_joint = (disc_bit_4.product(disc_bit_5, inplace=False)).product(disc_bit_6, inplace=False)
disc_joint.normalize()

P_e = 0.01
disc_bit_r_0 = DiscreteFactor(['b0', 'r0'], [2, 2], [1-P_e, P_e, P_e, 1-P_e])
disc_bit_r_1 = DiscreteFactor(['b1', 'r1'], [2, 2], [1-P_e, P_e, P_e, 1-P_e])
disc_bit_r_2 = DiscreteFactor(['b2', 'r2'], [2, 2], [1-P_e, P_e, P_e, 1-P_e])
disc_bit_r_3 = DiscreteFactor(['b3', 'r3'], [2, 2], [1-P_e, P_e, P_e, 1-P_e])
disc_bit_r_4 = DiscreteFactor(['b4', 'r4'], [2, 2], [1-P_e, P_e, P_e, 1-P_e])
disc_bit_r_5 = DiscreteFactor(['b5', 'r5'], [2, 2], [1-P_e, P_e, P_e, 1-P_e])
disc_bit_r_6 = DiscreteFactor(['b6', 'r6'], [2, 2], [1-P_e, P_e, P_e, 1-P_e])

print(disc_bit_r_0)

#actual sequence: 1 0 1 0 0 0 1
disc_bit_r_0.reduce([('r0', 1)])
disc_bit_r_1.reduce([('r1', 0)])
disc_bit_r_2.reduce([('r2', 1)])
disc_bit_r_3.reduce([('r3', 0)])
disc_bit_r_4.reduce([('r4', 1)])
disc_bit_r_5.reduce([('r5', 0)])
disc_bit_r_6.reduce([('r6', 1)])

disc_joint.product(disc_bit_r_0)
disc_joint.product(disc_bit_r_1)
disc_joint.product(disc_bit_r_2)
disc_joint.product(disc_bit_r_3)
disc_joint.product(disc_bit_r_4)
disc_joint.product(disc_bit_r_5)
disc_joint.product(disc_bit_r_6)

disc_joint.normalize()

print(disc_joint)

