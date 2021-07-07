import maya.cmds as mc

def parentObjects(parent, children=None):
  if type(children) == None:
    print "There are no children, please add some"
    children = input("Enter at least one child in the form ['child1', 'child2', ..]")

  mc.group(em=True, n=parent)
  for child in children:
    mc.parent(child, parent)

