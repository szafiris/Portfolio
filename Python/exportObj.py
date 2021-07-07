import maya.cmds as mc

def exportObj(assetName, exportLocation):
  '''
  Basic file exporter that exports files as OBJs
  args: 
  assetName: str, str[] of object names that you wish to export
  exportLocation: str of file path you wish to export to
  '''
  if type(assetName) == str:
    mc.select(assetName)
    mc.file(
    ''.join([exportLocation, assetName, '.obj']), 
    force=True, 
    type='OBJexport', 
    preserveReferences=False, 
    exportSelected=True
    )
  else:
    for asset in assetName:
      mc.select(asset, replace=True)
      mc.file(
      ''.join([exportLocation, asset, '.obj']), 
      force=True, 
      type='OBJexport', 
      preserveReferences=False, 
      exportSelected=True
      )
  return True

