#include "AreaLight.h"

bool
AreaLight::
intersect(const Ray&  _ray,
               vec3&  _intersection_point,
               vec3&  _intersection_normal,
             double&  _intersection_t) const
{
  _intersection_t = NO_INTERSECTION;

  if (plane.intersect(_ray, _intersection_point, _intersection_normal, _intersection_t))
  {
    vec3 center_to_point = _intersection_point - plane.getCenter();

    double dot_ctp_x_axis = fabs(dot(center_to_point, x_axis));
    double dot_ctp_y_axis = fabs(dot(center_to_point, y_axis));

    if (dot_ctp_x_axis <= x_size/2 && dot_ctp_y_axis <= y_size/2)
    {
      return true;
    }
  }
  return false;
}

vec3
AreaLight::
getLightPosition(int light_index)
{
  int ligth_x_index = light_index % x_parts ;
  int light_y_index = light_index / x_parts;

  vec3 temp = top_left + (ligth_x_index + 0.5) * block_side * x_axis + (light_y_index + 0.5) * block_side * y_axis;

  return temp;
}

vec3
AreaLight::
getLightIntensity(int light_index)
{
  return color / numberOfLights() ;
}
