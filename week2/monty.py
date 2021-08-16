from pgmpy.factors.discrete import TabularCPD

cpd_c = TabularCPD('C', 3, [[0.33], [0.33], [0.33]])
cpd_i = TabularCPD('I', 3, [[0.33], [0.33], [0.33]])
cpd_m = TabularCPD('M', 3, [[0, 0, 0, 0, 0.5, 1, 0, 1, 0.5],
                            [0.5, 0, 1, 0, 0, 0, 1, 0, 0.5],
                            [0.5, 1, 0, 1, 0.5, 0, 0, 0, 0]],
                            evidence= ['C', 'I'], evidence_card=[3,3])

print("Full Conditional Distribution:")
print(cpd_m)

cpd_joint = (cpd_m.product(cpd_i, inplace=False)).product(cpd_c,inplace=False)

cpd_joint = cpd_joint.to_factor()
print("Full Joint Distribution:")
print(cpd_joint)

cpd_joint.reduce([('I', 0),('M', 1)])
cpd_joint.normalize()
print("Reduced Distribution:")
print(cpd_joint)