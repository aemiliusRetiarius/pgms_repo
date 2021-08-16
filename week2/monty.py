from pgmpy.factors.discrete import TabularCPD

cpd_c = TabularCPD('C', 3, [[0.33], [0.33], [0.33]])
cpd_i = TabularCPD('I', 3, [[0.33], [0.33], [0.33]])
cpd_m = TabularCPD('M', 3, [[0, 0, 0, 0, 0.5, 1, 0, 1, 0.5],
                            [0.5, 0, 1, 0, 0, 0, 1, 0, 0.5],
                            [0.5, 1, 0, 1, 0.5, 0, 0, 0, 0]],
                            evidence= ['C', 'I'], evidence_card=[3,3])
cpd_r = TabularCPD('R', 3, [[0.5, 0.25, 0.25],
                            [0.25, 0.5, 0.25],
                            [0.25, 0.25, 0.5]],
                            evidence= ['M'], evidence_card=[3])

print("Full Conditional Distribution:")
print(cpd_m)

cpd_joint = (cpd_m.product(cpd_i, inplace=False)).product(cpd_c, inplace=False)
cpd_joint_r = (((cpd_r.product(cpd_i, inplace=False)).product(cpd_m, inplace=False)).product(cpd_i, inplace=False)).product(cpd_c, inplace=False)
print(cpd_joint_r)

cpd_joint = cpd_joint.to_factor()
cpd_joint_mar_m_unobs = cpd_joint.copy()
cpd_joint_mar_m = cpd_joint.copy()
cpd_joint_mar_m_obs = cpd_joint.copy()
cpd_joint_mar_c_unobs = cpd_joint.copy()
cpd_joint_mar_c_obs = cpd_joint.copy()


print("Full Joint Distribution:")
print(cpd_joint)

cpd_joint.reduce([('I', 0),('M', 1)])
cpd_joint.normalize()
print("Reduced Distribution:")
print(cpd_joint)

cpd_joint_mar_m_unobs.reduce([('I', 0)])
cpd_joint_mar_m_unobs.normalize()
cpd_joint_mar_m_unobs.marginalize(['M'])
print("Reduced Distribution (M unobserved):")
print(cpd_joint_mar_m_unobs)

cpd_joint_mar_m.reduce([('M', 0)])
cpd_joint_mar_m.normalize()
cpd_joint_mar_m.marginalize(['I'])
print("Reduced Distribution (M observed):")
print(cpd_joint_mar_m)

cpd_joint_mar_m_obs.reduce([('M', 0)])
cpd_joint_mar_m_obs.normalize()
cpd_joint_mar_m_obs.reduce([('I', 1)])
cpd_joint_mar_m_obs.normalize()
print("Reduced Distribution (M and I observed):")
print(cpd_joint_mar_m_obs)

cpd_joint_mar_c_unobs.reduce([('C', 0)])
cpd_joint_mar_c_unobs.normalize()
cpd_joint_mar_c_unobs.marginalize(['M'])
print("Reduced Distribution for I (M unobserved):")
print(cpd_joint_mar_c_unobs)

cpd_joint_mar_c_obs.reduce([('M', 0)])
cpd_joint_mar_c_obs.normalize()
cpd_joint_mar_c_obs.reduce([('I', 1)])
cpd_joint_mar_c_obs.normalize()
print("Reduced Distribution for I (M observed):")
print(cpd_joint_mar_c_obs)


