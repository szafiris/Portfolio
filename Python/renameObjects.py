import maya.cmds as mc


def renameObjects(name="Object", suffix="obj", index=1):
    '''
    Renames all the geometry in a scene
    '''

    objList = mc.ls(geometry=True)

    for obj in objList:
            newName = "{}_{}_{}".format(name, suffix, index)
            obj = obj.replace("Shape", '')
            mc.rename(obj, newName)
            index += 1
