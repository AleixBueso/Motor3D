#include "PhysVehicle3D.h"
#include "Primitive.h"
#include "Bullet\src\btBulletDynamicsCommon.h"

// ----------------------------------------------------------------------------
VehicleInfo::~VehicleInfo()
{
	//if(wheels != NULL)
		//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info, const VehicleInfo& info2) : PhysBody3D(body), vehicle(vehicle), info(info), info2(info2)
{
}

PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info, const VehicleInfo& info2, const VehicleInfo& info3, const VehicleInfo& info4, const VehicleInfo& info5) : PhysBody3D(body), vehicle(vehicle), info(info), info2(info2), info3(info3), info4(info4), info5(info5)
{
}


// ----------------------------------------------------------------------------
PhysVehicle3D::~PhysVehicle3D()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::RenderFront()
{
	Cylinder wheel;

	wheel.color = Black;

	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}

	Cube chassis(info.chassis_size.x, info.chassis_size.y, info.chassis_size.z);
	Cube cabin_truck(info2.chassis_size.x, info2.chassis_size.y, info2.chassis_size.z);
	chassis.color = Red;
	cabin_truck.color = Red;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&cabin_truck.transform);
	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());
	btVector3 offset2(info2.chassis_offset.x, info2.chassis_offset.y, info2.chassis_offset.z);
	offset2 = offset2.rotate(q.getAxis(), q.getAngle());

	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();

	cabin_truck.transform.M[12] += offset2.getX();
	cabin_truck.transform.M[13] += offset2.getY();
	cabin_truck.transform.M[14] += offset2.getZ();

	chassis.Render();
	cabin_truck.Render();
}

void PhysVehicle3D::RenderTrailer()
{
	Cylinder wheel;

	wheel.color = Black;

	for (int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}

	Cube chassis(info.chassis_size.x, info.chassis_size.y, info.chassis_size.z);
	Cube wall1(info2.chassis_size.x, info2.chassis_size.y, info2.chassis_size.z);
	Cube wall2(info3.chassis_size.x, info3.chassis_size.y, info3.chassis_size.z);
	Cube wall3(info4.chassis_size.x, info4.chassis_size.y, info4.chassis_size.z);
	Cube wall4(info5.chassis_size.x, info5.chassis_size.y, info5.chassis_size.z);

	chassis.color = Turquese;
	wall1.color = Turquese;
	wall2.color = Turquese;
	wall3.color = Turquese;
	wall4.color = Turquese;

	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&wall1.transform);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&wall2.transform);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&wall3.transform);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&wall4.transform);

	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();

	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	btVector3 offset2(info2.chassis_offset.x, info2.chassis_offset.y, info2.chassis_offset.z);
	btVector3 offset3(info3.chassis_offset.x, info3.chassis_offset.y, info3.chassis_offset.z);
	btVector3 offset4(info4.chassis_offset.x, info4.chassis_offset.y, info4.chassis_offset.z);
	btVector3 offset5(info5.chassis_offset.x, info5.chassis_offset.y, info5.chassis_offset.z);

	offset = offset.rotate(q.getAxis(), q.getAngle());
	offset2 = offset2.rotate(q.getAxis(), q.getAngle());
	offset3 = offset3.rotate(q.getAxis(), q.getAngle());
	offset4 = offset4.rotate(q.getAxis(), q.getAngle());
	offset5 = offset5.rotate(q.getAxis(), q.getAngle());

	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();

	wall1.transform.M[12] += offset2.getX();
	wall1.transform.M[13] += offset2.getY();
	wall1.transform.M[14] += offset2.getZ();

	wall2.transform.M[12] += offset3.getX();
	wall2.transform.M[13] += offset3.getY();
	wall2.transform.M[14] += offset3.getZ();

	wall3.transform.M[12] += offset4.getX();
	wall3.transform.M[13] += offset4.getY();
	wall3.transform.M[14] += offset4.getZ();

	wall4.transform.M[12] += offset5.getX();
	wall4.transform.M[13] += offset5.getY();
	wall4.transform.M[14] += offset5.getZ();

	chassis.Render();
	wall1.Render();
	wall2.Render();
	wall3.Render();
	wall4.Render();
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::ApplyEngineForce(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Brake(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Turn(float degrees)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3D::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}

void PhysVehicle3D::Orient(float angle_r)
{
	float matrix[16];
	memset(matrix, 0.0f, sizeof(matrix));

	// Keep position
	vec3 p = GetPos();
	matrix[12] = p.x;
	matrix[13] = p.y;
	matrix[14] = p.z;
	matrix[15] = 1;

	// Rotate the body by angle_r
	matrix[0] = cos(angle_r);
	matrix[2] = -sin(angle_r);
	matrix[5] = 1;
	matrix[8] = sin(angle_r);
	matrix[10] = cos(angle_r);

	SetTransform(matrix);
}

vec3 PhysVehicle3D::getForwardVector() const
{
	btVector3 vector = vehicle->getForwardVector();
	vec3 new_vector = { vector.getX(), vector.getY(), vector.getZ() };
	return new_vector;
}
