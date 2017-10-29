#include <iostream.h> 
#include <graphics.h> 
#include <stdio.h> 
#include <conio.h> 
#include <dos.h>

// upper limit for no of vertices
const int MAX = 20;
//const int BKCOLOR=LIGHTGRAY;
const int BKCOLOR = BLACK;
const int DRCOLOR = RED;
const int FILLCOLOR = WHITE;
const int SPECIAL = BLUE;
const int xorigin = 320;
const int yorigin = 240;
struct point {
  int x, y;
};
/*function:gets the vertices of the poly from the suitable source
  (currently using brute force for testing and simplifying purposes)
  paramaters: p1 has the poly, n has no of vertices
*/
void getdata(point p1[MAX], int & n);
/* used to copy p1 to p2 before sorting. as p2=p1 cant be done
 */
void copy(point p2[MAX], point p1[MAX], int n);
/* function:sorts the vertices of the polygon according to increasing y values
   sorting technique: insertion sort
   parameters: p (the polygon),n (used for sorting)
*/
void sort(point p[MAX], int n);
/* for testing purposes
 */
void display(point p[MAX], int n);
struct node {
  int ymax;
  float x, delx;
  node * link;
};
//sets up a node for the linked lists
node * getnode(int ymax1, float x1, float delx1);
/* GET tasks required:
1. insertion:insertion at end will do as its beneficial for the
   derived class AET.
2. sorting:the list has to be sorted according to the increasing x values
3. access head:give the address stored in the head node for merging the
   list in AET
5. searching:for constructing the table i need to see if an edge has
   been already inserted or not
6. display:this is required for the testing purposes
*/
class linked_list_GET {
  protected:
    node * head;
  public:
    linked_list_GET() {
      head = NULL;
    }
    /* i am passing a node to insert functions as
       to insert in AET i will remove nodes from GET and put
       in AET. as they wont be required by GET anymore.
       for insertion in GET prepare the node by calling getnode
       function and then call insert.
       this way i can insert lists at the end and in the beginning.
    */
  void insert_at_head(node * n);
  void insert_at_end(node * n);
  int sort();
  /* for merging a list in the AET address in the head pointer
     is required.this function returns that address
  */
  node * access_head() {
      return head;
    }
    /* searches the item in the list. in the end child
       points to the element searching for and parent
       points to the previous element.
       here the task is bascially whether an edge has been
       included in GET or not
    */
  int search(node * item, node * & parent, node * & child);
  void display();
};
/* AET tasks required:
1. insertion:have to insert a whole list from GET, hence doing insertion
   at end.(derived from the base class)
2. sorting:the list has to be sorted according to increasing x values
   (derived from the base class)
3. update:as y is increased new intersection points have to be calculated
4. delete:have to delete those edges which are complete
5. drawing:list has to be drawn in pairs
6. display:required for testing purposes (derived from the base class)
*/
class linked_list_AET: public linked_list_GET {
  public: linked_list_AET(): linked_list_GET() {

    }
    /* for a new scanline the new intersection points have
       to be calculated. this is done by x=x+delx (coherence
       property). update function performs this task
    */
  void update();
  /* this function checks whether the first or the last
     element has to be deleted or not
     return values:
     0:no
     1:yes
  */
  int del_first_or_last(int y);
  /* searches the item in the list. in the end child
     points to the element searching for and parent
     points to the previous element.
     return values:
     not found:0
     found:1
  */
  int search(int y, node * & parent, node * & child);
  /* return values:
     no deletion:0
     deletion:1
  */
  int delete_first();
  /* have to use this only when in AET ymax of an edge
     is reached. hence search for y and delete if found
     also i want to know if anyone of the first or the last
     node is being deleted.
     return values:
     no deletion:0
     deletion:1
  */
  int delete_item(int y);
  /* to fill the polygon we have to draw in pairs from the
     x values of the node at the y value passed as an argument.
  */
  void draw(int y);
};
/* array for the lists of GET. as no of edges cant exceed no
   of vertices,no of lists are even lesser so this is a safe upper limit
   the array yindex stores the y value at which the list at the corresponding
   index in both arrays would be in the actual algo.
*/
linked_list_GET GET[MAX];
int yindex[MAX] = {
  0
};
/* for non horizontal edges gets a node and inserts it in appropriate list
   paramenters:
   a: the current vertex
   b: the adjoining vertex
*/
void make_insert_edge(point a, point b, int ycur);
/* take each edge one by one starting from ymin and put it in the
   corredponding position in GET and the y value in yindex
   paramenters: p1 ,p2, n (polygon data)
   after this function call GET is completely ready
*/
void make_GET(point p1[MAX], point p2[MAX], int n);
void goto_graphics_mode();
void draw_poly(point p[MAX], int n);
/* start with empty list and move from ymin to ymax.
   for every y do
	   update
	   merge
	   sort
	   delete
	   draw
   if delete from 1st or last then first draw and delete,
   then do the normal draw
   parameters:
   p2,n:required to get ymin and ymax
*/
void process_AET(point p2[MAX], int n);
void scanline(point p1[MAX], point p2[MAX], int n) {
  /* polygon obtained. now sort them according to increasing y values
  	   and store them in another array
  	*/
  copy(p2, p1, n);
  sort(p2, n);
  /* polygon in both arrays. make GET(global edge table).
     this completes the GET with all the lists sorted also
  */
  make_GET(p1, p2, n);
  goto_graphics_mode();
  draw_poly(p1, n);
  /* now just process AET. this fills the polygon
   */
  process_AET(p2, n);
}
void main() {
  /*p1 is the polygon with the vertices in the cyclic order
    n has the no of vertices in the polygon
  */
  point p1[MAX], p2[MAX];
  int n;
  /*the vertices of the polygon should be stored in the text file
  polygon.txt but for testing and simplifying purposes using
  brute force, so first retrieve them and store in p1
  */
  getdata(p1, n);
  scanline(p1, p2, n);
  getch();
}
void getdata(point p1[MAX], int & n) {
  n = 19;

  p1[0].x = 2;
  p1[0].y = 5;
  p1[1].x = 2;
  p1[1].y = 7;
  p1[2].x = 4;
  p1[2].y = 7;
  p1[3].x = 4;
  p1[3].y = 9;
  p1[4].x = 6;
  p1[4].y = 9;
  p1[5].x = 6;
  p1[5].y = 7;
  p1[6].x = 8;
  p1[6].y = 7;
  p1[7].x = 9;
  p1[7].y = 9;
  p1[8].x = 10;
  p1[8].y = 9;
  p1[9].x = 10;
  p1[9].y = 7;
  p1[10].x = 14;
  p1[10].y = 7;
  p1[11].x = 12;
  p1[11].y = 1;
  p1[12].x = 10;
  p1[12].y = 1;
  p1[13].x = 10;
  p1[13].y = 3;
  p1[14].x = 8;
  p1[14].y = 3;
  p1[15].x = 8;
  p1[15].y = 1;
  p1[16].x = 6;
  p1[16].y = 1;
  p1[17].x = 6;
  p1[17].y = 3;
  p1[18].x = 4;
  p1[18].y = 3;
  for (int i = 0; i < n; i++) {
    p1[i].x *= 10;
    p1[i].y *= 10;
  }
}
void copy(point p2[MAX], point p1[MAX], int n) {
  for (int i = 0; i < n; i++) {
    p2[i].x = p1[i].x;
    p2[i].y = p1[i].y;
  }
}
void sort(point p[MAX], int n) { //using insertion sort
  point temp;
  for (int i = 1; i < n; i++) {
    temp = p[i];
    for (int j = i;
      ((temp.y < p[j - 1].y) && j > 0); j--)
      p[j] = p[j - 1];
    p[j] = temp;
  }
}
void display(point p[MAX], int n) {
  for (int i = 0; i < n; i++) {
    cout << p[i].x << "," << p[i].y << "     ";
  }
  getch();
}
node * getnode(int ymax1, float x1, float delx1) {
  node * n = new node;
  n - > ymax = ymax1;
  n - > x = x1;
  n - > delx = delx1;
  n - > link = NULL;
  return n;
}
void linked_list_GET::insert_at_head(node * n) { //this enables a list to be inserted at head
  node * temp = n;
  while (temp - > link != NULL)
    temp = temp - > link;
  temp - > link = head;
  head = n;
}
void linked_list_GET::insert_at_end(node * n) {
  if (head == NULL)
    insert_at_head(n);
  else {
    node * temp = head;
    //go to the end
    while (temp - > link != NULL)
      temp = temp - > link;
    /* place the new data at the end
       more than one node can be inserted at a time.
       to be specific a list can be concatenated at the end
    */
    temp - > link = n;
  }
}
int linked_list_GET::sort() {
  if (head == NULL)
    return 0;
  else {
    node * temp1 = head;
    node * temp2 = head;
    node * temp_pos = NULL;
    int temp_ymax;
    float temp;
    while (temp1 - > link != NULL)
      temp1 = temp1 - > link;
    //temp1 is at the last node
    while (temp1 != head) {
      temp2 = head;
      while (temp2 != temp1) {
        if (temp2 - > x > temp2 - > link - > x) { //swapping values
          temp_ymax = temp2 - > ymax;
          temp2 - > ymax = temp2 - > link - > ymax;
          temp2 - > link - > ymax = temp_ymax;
          temp = temp2 - > x;
          temp2 - > x = temp2 - > link - > x;
          temp2 - > link - > x = temp;
          temp = temp2 - > delx;
          temp2 - > delx = temp2 - > link - > delx;
          temp2 - > link - > delx = temp;
        }
        temp_pos = temp2;
        temp2 = temp2 - > link;
      }
      temp1 = temp_pos;
    }
    return 1;
  }
}
int linked_list_GET::search(node * item, node * & parent, node * & child) { //parent follows the child
  child = head;
  while (child != NULL) {
    if (child - > ymax == item - > ymax && child - > x == item - > x && child - > delx == item - > delx)
      return 1;
    parent = child;
    child = child - > link;
  }
  return 0;
}
void linked_list_GET::display() {
  if (head == NULL)
    cout << "Empty list.";
  else {
    cout << "The list is:" << endl;
    node * temp = head;
    while (temp != NULL) {
      cout << temp - > ymax << "," << temp - > x << "," << temp - > delx << "    ";
      temp = temp - > link;
    }
  }
}
void linked_list_AET::update() {
  node * temp = head;
  //for all nodes do x+=delx
  while (temp != NULL) {
    (temp - > x) = (temp - > x) + (temp - > delx);
    temp = temp - > link;
  }
}
int linked_list_AET::del_first_or_last(int y) { //first element
  if (head - > ymax == y)
    return 1;
  else {
    node * temp = head;
    //last element
    while (temp - > link != NULL)
      temp = temp - > link;
    if (temp - > ymax == y)
      return 1;
  }
  return 0;
}
int linked_list_AET::search(int y, node * & parent, node * & child) { //parent follows the child
  child = head;
  while (child != NULL) {
    if (child - > ymax == y)
      return 1;
    parent = child;
    child = child - > link;
  }
  return 0;
}
int linked_list_AET::delete_first() {
  if (head == NULL)
    return 0;
  node * n = head;
  head = head - > link;
  free(n);
  return 1;
}
int linked_list_AET::delete_item(int y) {
  node * parent;
  node * child;
  if (search(y, parent, child)) {
    if (child == head)
      return delete_first();
    else {
      parent - > link = child - > link;
      free(child);
      return 1;
    }
  } else
    return 0;
}
void linked_list_AET::draw(int y) {
  node * temp = head;
  int first, next;
  while (temp != NULL) { //move forward by 2 to draw in pairs
    first = temp - > x;
    temp = temp - > link;
    if (temp == NULL)
      break;
    next = temp - > x;
    temp = temp - > link;
    line(xorigin + first, yorigin - y, xorigin + next, yorigin - y);
  }
}
void make_insert_edge(point a, point b, int ycur) {
  if (a.y != b.y) //for non horizontal edges
  {
    int ymax, x;
    //select ymax and x(ymin)
    if (a.y > b.y) {
      ymax = a.y;
      x = b.x;
    } else {
      ymax = b.y;
      x = a.x;
    }
    float delx = (a.x - b.x) * 1.0 / (a.y - b.y);
    node * temp = getnode(ymax, x, delx);
    //check if this edge has already been included in GET or not
    int found = 0;
    for (int i = 0; i <= ycur; i++) {
      if (GET[i].search(temp, NULL, NULL)) {
        found = 1;
        break;
      }
    }
    //if edge is not included then include it else free temp
    if (!found)
      GET[ycur].insert_at_end(temp);
    else
      free(temp);
  }
}
void make_GET(point p1[MAX], point p2[MAX], int n) {
    /* this tells the current y location and is required to know if the
    	   new edge will be inserted in the current list or next higher list
    	*/
    int ycur = 0;
    /*for a vertex these tell the index of adjoining vertices in p1
     */
    int e1, e2;
    /* for each vertex in p2 look what edges can be formed leaving aside
       horizontal edges
    */
    yindex[0] = p2[0].y; //otherwise the first pointer will almost always be NULL
    for (int i = 0; i < n; i++) { /* if edges goes in next list increment ycur */
      if (yindex[ycur] < p2[i].y) { //list finish so sort it and start a new list
        GET[ycur].sort();
        ycur++;
      }
      yindex[ycur] = p2[i].y;
      //search for curent vertex of p2 in p1
      for (int j = 0; j < n; j++) {
        if (p1[j].x == p2[i].x && p1[j].y == p2[i].y)
          break;
      }
      /* a%n=(a%n+n)%n this gives the right result for both
         positive and negative nos in the required form ie
         positive no suitable for getting edges from arrays
      */
      e1 = ((j + 1) % n + n) % n;
      e2 = ((j - 1) % n + n) % n;
      node * temp;
      make_insert_edge(p2[i], p1[e1], ycur);
      make_insert_edge(p2[i], p1[e2], ycur);
    } //for}
    void goto_graphics_mode() {
      int gdriver = DETECT, gmode, errorcode;
      initgraph( & gdriver, & gmode, "C:\\TURBOC3\\BGI");
      errorcode = graphresult();
      if (errorcode != grOk) {
        cout << "Graphics error:" << grapherrormsg(errorcode);
        cout << "Press any key to halt:";
        getch();
        exit(1); /* terminate with an error code */
      }
      setbkcolor(BKCOLOR);
      setcolor(DRCOLOR);
    }
    void draw_poly(point p[MAX], int n) {
      for (int i = 0; i < n; i++) {
        line(xorigin + p[i].x, yorigin - p[i].y, xorigin + p[(i + 1) % n].x, yorigin - p[(i + 1) % n].y);
      }
    }
    void process_AET(point p2[MAX], int n) {
      linked_list_AET AET;
      /* get ymin and ymax
         ymin=p2[0].y; ymax=p2[n-1].y;
      */
      int ycur = 0;
      for (int i = p2[0].y; i <= p2[n - 1].y; i++) {
        AET.update();
        /* merging
           if GET list for current i exists merge the list into AET
           and increment the pointer,for next non empty list, ycur
        */
        if (i == yindex[ycur]) {
          AET.insert_at_end(GET[ycur].access_head());
          ycur++;
        }
        AET.sort();
        /* deletion
           if 1st or last element is to be deleted,
           then first draw and then delete
           and do this for all the nodes that are to be deleted
        */
        int flag = 0;
        /* find if there is deletion from 1st or last node
           if yes then draw and del all else just del all
        */
        flag = AET.del_first_or_last(i);
        if (flag) {
          setcolor(SPECIAL);
          AET.draw(i);
          //AET.display();
          getch();
        }
        flag = 1;
        while (flag) {
          flag = AET.delete_item(i);
        }
        /*		AET.display();
        		cout<<endl<<endl;
        */
        setcolor(FILLCOLOR);
        AET.draw(i);
        getch();
      }
    }