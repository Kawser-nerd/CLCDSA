# http://code.google.com/p/pyeuclid/
import euclid

def main():
    T = int(raw_input())
    for case in xrange(T):
        N = int(raw_input())
        position = euclid.Vector3()
        velocity = euclid.Vector3()
        for _ in xrange(N):
            x, y, z, vx, vy, vz = map(float, raw_input().split())
            position += euclid.Vector3(x, y, z)
            velocity += euclid.Vector3(vx, vy, vz)
        position /= N
        velocity /= N
        if velocity == euclid.Vector3():
            d_min = abs(position - euclid.Point3())
            t_min = 0.
        else:
            position = euclid.Point3(position.x, position.y, position.z)
            ray = euclid.Ray3(position, velocity)
            connection = ray.connect(euclid.Point3())
            d_min = abs(connection)
            t_min = abs(connection.p1 - position) / abs(velocity)
        print 'Case #%d: %1.8f %1.8f' % (case + 1, d_min, t_min)

if __name__ == '__main__':
    main()
