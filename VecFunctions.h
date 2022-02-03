#pragma once
#include <math.h>
#include "Vec2.h"
#include "Vec3.h"

float clamp(float value, float min, float max) { return fmax(fmin(value, max), min); }
double sign(double a) { return (0 < a) - (a < 0); }
double step(double edge, double x) { return x > edge; }

float length(vec2 const& v) { return sqrt(v.x * v.x + v.y * v.y); }

float length(vec3 const& v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }

vec3 norm(vec3 v) { return v / length(v); }

// scalar multiplication
float dot(vec3 const& a, vec3 const& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

vec3 abs(vec3 const& v) { return vec3(fabs(v.x), fabs(v.y), fabs(v.z)); }

vec3 sign(vec3 const& v) { return vec3(sign(v.x), sign(v.y), sign(v.z)); }

vec3 step(vec3 const& edge, vec3 v) { return vec3(step(edge.x, v.x), step(edge.y, v.y), step(edge.z, v.z)); }

vec3 reflect(vec3 rd, vec3 n) { return rd - n * (2 * dot(n, rd)); }

vec3 rotateX(vec3 a, double angle)
{
    vec3 b = a;
    b.z = a.z * cos(angle) - a.y * sin(angle);
    b.y = a.z * sin(angle) + a.y * cos(angle);
    return b;
}

vec3 rotateY(vec3 a, double angle)
{
    vec3 b = a;
    b.x = a.x * cos(angle) - a.z * sin(angle);
    b.z = a.x * sin(angle) + a.z * cos(angle);
    return b;
}

vec3 rotateZ(vec3 a, double angle)
{
    vec3 b = a;
    b.x = a.x * cos(angle) - a.y * sin(angle);
    b.y = a.x * sin(angle) + a.y * cos(angle);
    return b;
}

// line: ro + rd*t <-> o+dt
// sphere: (x-x0)^2+(y-y0)^2+(z-z0)^2=r^2
// sphere in vec form: (m-so)^2=r^2
// m = o+dt
// (dt + (o-c))^2-r^2=0
// ...
// a = d^2; b = 2d(o-so); c = ((o-so)^2 - r^2);
// t = (-b +/- sqrt(b^2 - 4ac))/2a
// can be optimised
vec2 sphere(vec3 ro_sub_so, vec3 rd, float r) {
    float a = dot(rd, rd);
    float b = 2*dot(rd, ro_sub_so);
    float c = dot(ro_sub_so, ro_sub_so)-r*r;
    if (b * b - 4 * a * c < 0) return vec2(-1.0);
    else return vec2(( - b + sqrt(b * b - 4 * a * c))/(2*a), (-b - sqrt(b * b - 4 * a * c)) / (2 * a));
}

vec2 box(vec3 ro, vec3 rd, vec3 boxSize, vec3& outNormal) {
    vec3 m = vec3(1.0) / rd;
    vec3 n = m * ro;
    vec3 k = abs(m) * boxSize;
    vec3 t1 = -n - k;
    vec3 t2 = -n + k;
    float tN = fmax(fmax(t1.x, t1.y), t1.z);
    float tF = fmin(fmin(t2.x, t2.y), t2.z);
    if (tN > tF || tF < 0.0) return vec2(-1.0);
    vec3 yzx = vec3(t1.y, t1.z, t1.x);
    vec3 zxy = vec3(t1.z, t1.x, t1.y);
    outNormal = -sign(rd) * step(yzx, t1) * step(zxy, t1);
    return vec2(tN, tF);
}

float plane(vec3 ro, vec3 rd, vec3 p, float w) {
    return -(dot(ro, p) + w) / dot(rd, p);
}