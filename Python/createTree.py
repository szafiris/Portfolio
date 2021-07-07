import maya.cmds as mc
from exportObj import exportObj
from exportFBX import exportFBX

def color(object, material, color, export=False, fbx=False): 
  mc.sets(name=material+'MaterialGroup', renderable=True, empty=True)
  mc.shadingNode(material, name=material+'Shader', asShader=True)
  mc.setAttr(material+'Shader.color', color[0], color[1], color[2], type='double3')
  mc.surfaceShaderList(material+'Shader', add=material+'MaterialGroup')
  mc.sets(object, e=True, forceElement=material+'MaterialGroup')

def createTree(leafColor=[0,0.39,0], trunkColor=[0.36,0.25,0.2], treeName="My Tree"):
  trunkObj, trunkNode = mc.polyCylinder(n="trunk", h=20)
  leafObj, leafNode = mc.polyCone(n="leaves", h=40, r=10)

  mc.move(0, 20, 0)
  color(trunkObj, 'blinn', trunkColor)
  color(leafObj, 'lambert', leafColor)

  mc.polyUnite(trunkObj, leafObj, n='tree')
  mc.move(0, 10, 0)

  if export:
    if fbx:
      exportFBX('tree', "C:/Users/smzaf/OneDrive/Documents/Method/Codes/")  
    else:
      exportObj('tree', "C:/Users/smzaf/OneDrive/Documents/Method/Codes/")

createTree()