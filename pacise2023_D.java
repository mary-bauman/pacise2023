//https://lightoj.com/contest/esu-final-pacise/arena/problem/3808
import java.util.*;

public class pacise2023_D {
    
public static class Point {
	public int x, y;
	public Point(int x, int y){
        this.x = x;
        this.y = y;
	}
}

public static class Line {
	public Point p1, p2;
	public Line(Point p1, Point p2){
        this.p1 = p1;
        this.p2 = p2;
	}
}

static int onLine(Line l1, Point p){
	if (p.x <= Math.max(l1.p1.x, l1.p2.x)
		&& p.x <= Math.min(l1.p1.x, l1.p2.x)
		&& (p.y <= Math.max(l1.p1.y, l1.p2.y)
			&& p.y <= Math.min(l1.p1.y, l1.p2.y)))
	return 1;

	return 0;
}

static int direction(Point a, Point b, Point c){
	int val = (b.y - a.y) * (c.x - b.x)- (b.x - a.x) * (c.y - b.y);

	if (val == 0)	return 0;
	else if (val < 0) return 2;

	return 1;
}

static int isIntersect(Line l1, Line l2){
	int dir1 = direction(l1.p1, l1.p2, l2.p1);
	int dir2 = direction(l1.p1, l1.p2, l2.p2);
	int dir3 = direction(l2.p1, l2.p2, l1.p1);
	int dir4 = direction(l2.p1, l2.p2, l1.p2);

	if (dir1 != dir2 && dir3 != dir4) return 1;

	if (dir1 == 0 && onLine(l1, l2.p1) == 1) return 1;
	if (dir2 == 0 && onLine(l1, l2.p2) == 1) return 1;
	if (dir3 == 0 && onLine(l2, l1.p1) == 1) return 1;
	if (dir4 == 0 && onLine(l2, l1.p2) == 1) return 1;

	return 0;
}

static int checkInside(Point[] poly, int n, Point p){
	if (n < 3) return 0;
	Point pt = new Point(9999, p.y);
	Line exline = new Line(p, pt);
	int count = 0;
	int i = 0;
	do {
        Line side = new Line(poly[i], poly[(i + 1) % n]);
        if (isIntersect(side, exline) == 1) {
            if (direction(side.p1, p, side.p2) == 0) return onLine(side, p);
            count++;
        }
        i = (i + 1) % n;
	} while (i != 0);

	return count & 1;
}

public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int vertices = Integer.parseInt(sc.nextLine());
	Point[] polygon = new Point[vertices];
    for(int a = 0; a<vertices; a++){
        String [] line = sc.nextLine().split(" ");
        int xx = Integer.parseInt(line[0]);
        int yy = Integer.parseInt(line[1]);
        polygon[a] = new Point(xx,yy);
    }
    String [] line2 = sc.nextLine().split(" ");
    int x2 = Integer.parseInt(line2[0]);
    int y2 = Integer.parseInt(line2[1]);
	Point p = new Point(x2, y2);
	int n = vertices;
	if (checkInside(polygon, n, p) == 1) System.out.println("inside");
	else System.out.println("outside");
}
}
