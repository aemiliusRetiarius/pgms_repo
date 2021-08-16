from pgmpy.factors.discrete import TabularCPD

#define distributions
cpd_x = TabularCPD('X', 2, [[0.5], [0.5]])
cpd_y = TabularCPD('Y', 2, [[0.5], [0.5]])
cpd_z = TabularCPD('Z', 3, [[1, 0, 0, 0],
                            [0, 1, 1, 0],
                            [0, 0, 0, 1]],
                            evidence= ['X', 'Y'], evidence_card=[2,2])

print("Conditional Distribution for Z:")
print(cpd_z)

cpd_joint = (cpd_x.product(cpd_y, inplace=False)).product(cpd_z,inplace=False)

print("Joint Distribution:")
print(cpd_joint)

