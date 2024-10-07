#include <Matrix.h>


//template<typename T>
//Matrix<T> Matrix<T>::toTriangle(std::vector<T> dop)
//{
//	Matrix<T> nm(this);
//	for (int k = 0; k < _n-1; ++k) {
//		for (int i = k + 1; i < _n; ++i) {
//			T coef = -nm._arr[i * _m + k] / nm._arr[k * _m + k];
//			for (int j = k; j < _m; ++j) {
//				nm._arr[i * _m + j] += coef * nm._arr[k * _m + j];
//			}
//			dop[i] += coef * dop[k];
//		}
//	}
//	return nm;
//}

mat3::mat3(float elem)
{
	for (size_t i = 0; i < 9; ++i) {
		_arr[i] = elem;
	}
}

mat3::mat3(const mat3& m)
{
	for (size_t i = 0; i < 9; ++i) {
		_arr[i] = m._arr[i];
	}
}

mat3 mat3::one() {
	mat3 res;
	res._arr[0] = 1;
	res._arr[4] = 1;
	res._arr[8] = 1;
	return res;
}

vec3 mat3::operator*(const vec3& v)
{
	return vec3(_arr[0] * v.x + _arr[1] * v.y + _arr[2] * v.z, _arr[3] * v.x + _arr[4] * v.y + _arr[5] * v.z, _arr[6] * v.x + _arr[7] * v.y + _arr[8] * v.z);
}

mat3::mat3(vec3& a, vec3& b, vec3& c)
{
	vec3 arr[3]{ a,b,c };
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0;j<3; ++j) {
			_arr[i * 3 + j] = arr[i][j];
		}
	}
}

vec3 mat3::operator[](const int i)
{
	return vec3(_arr[i*3],_arr[i*3+1],_arr[i*3+2]);
}

mat3 mat3::operator+(const mat3& m)
{
	mat3 res;
	for (size_t i = 0; i < 9; ++i) {
		res._arr[i] = _arr[i] + m._arr[i];
	}
	return res;
}

mat3 mat3::operator-(const mat3& m)
{
	mat3 res;
	for (size_t i = 0; i < 9; ++i) {
		res._arr[i] = _arr[i] + m._arr[i];
	}
	return res;
}

mat3 mat3::operator*(const float f)
{
	mat3 res;
	for (size_t i = 0; i < 9; ++i) {
		res._arr[i] = _arr[i] * f;
	}
	return res;
}

bool mat3::operator==(const mat3& m)
{
	bool res = true;
	for (size_t i = 0; i < 9 && res; ++i) {
		res = (_arr[i] == m._arr[i]);
	}
    return res;
}

mat3 operator*(const float f, const mat3& m)
{
	mat3 res;
	for (size_t i = 0; i < 9; ++i) {
		res._arr[i] = m._arr[i] * f;
	}
	return res;
}

