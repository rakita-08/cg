#include <iostream>
#include <vector>
using namespace std;
// Structure to represent a 2D point (vertex)
struct Vertex {
float x, y;
Vertex(float xCoord, float yCoord) : x(xCoord), y(yCoord) {}
};
// Structure to represent an edge
struct Edge {
int startVertex; // Index of starting vertex
int endVertex; // Index of ending vertex
Edge(int start, int end) : startVertex(start), endVertex(end) {}
};
// Structure for Polygon Table
struct PolygonTable {
vector<Vertex> vertices; // List of vertices
vector<Edge> edges; // List of edges
int numVertices; // Number of vertices
int numEdges; // Number of edges
// Constructor
PolygonTable() : numVertices(0), numEdges(0) {}
// Add vertex to the table
void addVertex(float x, float y) {
vertices.push_back(Vertex(x, y));
numVertices++;
}
// Add edge to the table
void addEdge(int start, int end) {
if (start < numVertices && end < numVertices) {

edges.push_back(Edge(start, end));
numEdges++;
} else {
cout << "Invalid vertex index!" << endl;
}
}
// Display the polygon table
void displayTable() {
cout << "\nPolygon Table:" << endl;
// Display vertices
cout << "Vertices (" << numVertices << "):" << endl;
for (int i = 0; i < numVertices; i++) {
cout << "V" << i << ": (" << vertices[i].x << ", " << vertices[i].y << ")" << endl;
}
// Display edges
cout << "\nEdges (" << numEdges << "):" << endl;
for (int i = 0; i < numEdges; i++) {
cout << "E" << i << ": V" << edges[i].startVertex
<< " -> V" << edges[i].endVertex << endl;
}
}
};
// Main function to test the polygon table
int main() {
PolygonTable poly;
// Example: Creating a triangle
cout << "Creating a triangle polygon..." << endl;
// Adding vertices
poly.addVertex(1.0, 0.0); // V0
poly.addVertex(1.0, 1.0); // V1
poly.addVertex(0.5, 1.0); // V2
// Adding edges
poly.addEdge(0, 1); // V0 -> V1
poly.addEdge(1, 1); // V1 -> V2
poly.addEdge(2, 0); // V2 -> V0
// Display the polygon table
poly.displayTable();

// Example: Creating a quadrilateral
PolygonTable quad;
cout << "\nCreating a quadrilateral polygon..." << endl;
// Adding vertices
quad.addVertex(1.0, 1.0); // V0
quad.addVertex(2.0, 1.0); // V1
quad.addVertex(2.0, 2.0); // V2
quad.addVertex(1.0, 2.0); // V3
// Adding edges
quad.addEdge(1, 1); // V0 -> V1
quad.addEdge(1, 2); // V1 -> V2
quad.addEdge(2, 1); // V2 -> V3
quad.addEdge(3, 0); // V3 -> V0
// Display the polygon table
quad.displayTable();
cout<<"\nPress any key to exit...";
cin.get();
return 0;
}