#pragma once
namespace Math3d {
	class Vector3D
	{
		float Vect[3];
	public:
		Vector3D(const Vector3D&) = delete;
		Vector3D(float x=0, float y=0, float z=0);
		void Print();
		float at(unsigned int)const;
		float& operator[](unsigned int);
		bool operator==(const Vector3D&)const;
		bool operator!=(const Vector3D&)const;
		Vector3D& operator=(const Vector3D&)=delete;
	};
}
