import maya.cmds as mc


def moveObjects(Tx=0, Ty=0, Tz=0):
    '''
      Moves all the geometry in a scene
      '''

    objList = mc.ls(geometry=True)

    for obj in objList:
      obj = obj.replace("Shape", '')
      mc.setAttr("{}.translateX".format(obj), Tx)
      mc.setAttr("{}.translateY".format(obj), Ty)
      mc.setAttr("{}.translateZ".format(obj), Tz)



