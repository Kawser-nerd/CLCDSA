class Rectangle:
    def __init__(self, coords):
        self.x1 = coords[0]
        self.y1 = coords[1]
        self.x2 = coords[2]
        self.y2 = coords[3]
        self.neighbours = []
        self.visited = False

    def neighbour(r1, r2):
        if r1.y1 <= r2.y2 and r1.y2 >= r2.y1 and r1.x1 <= r2.x2 and r1.x2 >= r2.x1:
            return True
        if r1.y1 - r2.y2 == 1 and r1.x1 <= r2.x2 and r1.x2 >= r2.x1:
            return True
        if r2.y1 - r1.y2 == 1 and r2.x1 <= r1.x2 and r2.x2 >= r1.x1:
            return True
        if r1.x1 - r2.x2 == 1 and r1.y1 <= r2.y2 and r1.y2 >= r2.y1:
            return True
        if r2.x1 - r1.x2 == 1 and r2.y1 <= r1.y2 and r2.y2 >= r1.y1:
            return True
        if r1.x2 == r2.x1 - 1 and r1.y1 == r2.y2 + 1:
            return True
        if r2.x2 == r1.x1 - 1 and r2.y1 == r1.y2 + 1:
            return True
        return False

    def addToRegion(self, region):
        assert not self.visited
        #print "Appending", self, region
        self.visited = True
        if (self.x1 + self.y1 < region.minx + region.miny):
            region.minx = self.x1
            region.miny = self.y1
        if (self.x2 > region.maxx):
            region.maxx = self.x2
        if (self.y2 > region.maxy):
            region.maxy = self.y2
        for neigh in self.neighbours:
            if not neigh.visited:
                neigh.addToRegion(region)

class Region:
    def __init__(self, rect):
        self.minx = 10000000
        self.miny = 10000000
        self.maxx = -1
        self.maxy = -1
        rect.addToRegion(self)
        
    def timetodie(self):
        return max(0, self.maxx-self.minx + self.maxy-self.miny + 1)

infile = open("C-large.in", "r")

T = int(infile.readline().strip())

for t in range(T):
    R = int(infile.readline().strip())
    rectangles = []
    for r in range(R):
        coords = eval("("+infile.readline().strip().replace(' ',',')+")");
        rect = Rectangle(coords)
        for rect2 in rectangles:
            if rect.neighbour(rect2):
                rect.neighbours.append(rect2)
                rect2.neighbours.append(rect)
        rectangles.append(rect);
    # join up the rectangles
    regions = []
    for rect in rectangles:
        if not rect.visited:
            regions.append(Region(rect))
    #print regions
    ans = 0
    for region in regions:
        ans = max(ans, region.timetodie())
    print "Case #" + str(t+1) + ": " + str(ans)
