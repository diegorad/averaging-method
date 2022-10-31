import bpy

me = bpy.context.object.data

filepath = "/Users/diegorad/Documents/Averaging/test_mesh.dat"
f = open(filepath, "w")

f.write("%d %d\n" % (len(me.vertices),len(me.polygons)))

verts = [ bpy.context.object.matrix_world @ v.co for v in me.vertices ]
ssvLines = [ " ".join([str(v) for v in co]) + "\n" for co in verts]
f.writelines(ssvLines)

for poly in me.polygons:
    f.write("%d\n" % poly.loop_total)

for poly in me.polygons:    
    for loop_index in range(poly.loop_start, poly.loop_start + poly.loop_total):
        f.write("%d " % me.loops[loop_index].vertex_index)
    f.write("\n")
    
for polygon in me.polygons:
    f.write("%lf %lf\n" % (polygon.center[0],polygon.center[1]))

f.close()         
