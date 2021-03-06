#include <stdio.h>

#define RECTANGLE 0;
#define CIRCLE 1;

// Suppose that s is the following structure (point is a structure tag declared in Exercise 10):
struct point {
	int x, y;
};

struct shape {
	int shape_kind;               //RECTANGLE or CIRCLE //
	// enum {RECTANGLE, CIRCLE} shape_kind;
	struct point center;          // coordinates of center //
	union {
		struct {
			int height, width;
		} rectangle;
		struct { int radius;
		} circle;
	} u;
} s;

// If the value of shape_kind is RECTANGLE, the height and width members store the
// dimensions of a rectangle. If the value of shape_kind is CIRCLE, the radius member
// stores the radius of a circle. Indicate which of the following statements are legal,
// and show how to repair the ones that aren't:

int main (void)
{
// (a) s.shape_kind = RECTANGLE;
	s.shape_kind = RECTANGLE;
	
// (b) s.center.x = 10;
	s.center.x = 10;
	
// (c) s.height = 25; wrong
	s.u.rectangle.height = 25;
		
// (d) s.u.rectangle.width = 8;
	s.u.rectangle.width = 8;
	
// (e) s.u.circle = 5; wrong
	s.u.circle.radius = 5;
	
// (f) s.u.radius = 5; wrong
	s.u.circle.radius = 5;

	return 0;
}
