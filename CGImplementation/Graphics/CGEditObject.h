#ifndef __CG_EDIT_OBJECT_H__
#define __CG_EDIT_OBJECT_H__

#include <GPED/GPED_Precision.h>

namespace CGProj
{
	enum EditObjectType
	{
		EDIT_PROXY_OBJECT = 0, // Proxy means just normal real objects in game world
		EDIT_LIGHT_OBJECT // light object
	};

	enum EditPrimitiveType // this enum is used to represent object collider
	{
		EDIT_PRIMITIVE_AABB = 0,
		EDIT_PRIMITIVE_OBB,
		EDIT_PRIMITIVE_SPHERE
	};

	enum EditProxyType
	{
		EDIT_PROXY_STATIC = 0,
		EDIT_PROXY_DYNAMIC
	};

	enum EditLightType
	{
		EDIT_DIRECTION_LIGHT = 0,
		EDIT_POINT_LIGHT,
		EDIT_SPOT_LIGHT
	};

	// This class includes all of information of any objects in Game World
	// to control the properties of each object like physics object, graphics object, 
	// and so on.
	class CGEditObject
	{
	public:
		void setObjectType(EditObjectType t);
		EditObjectType getObjectType();

		void setPrimitiveType(EditPrimitiveType t);
		EditPrimitiveType getPrimitiveType();

		void setProxyType(EditProxyType t);
		EditProxyType getProxyType();

		void setLightType(EditLightType t);
		EditLightType getLightType();
	protected:
		EditObjectType m_ObjectType;
		EditPrimitiveType m_PrimitiveType;
		EditProxyType m_proxyType;
		EditLightType m_LightType;
	};

	class CGEditBox : CGEditObject
	{
	public:
		CGEditBox(EditObjectType oT, EditPrimitiveType pT, EditProxyType proxyT);
		CGEditBox(EditObjectType oT, EditPrimitiveType pT, EditLightType lT);

		void setPosition(const glm::vec3& p);
		void setPosition(const GPED::real x, const GPED::real y, const GPED::real z);
		void setXposition(const GPED::real x);
		void setYposition(const GPED::real y);
		void setZposition(const GPED::real z);
		glm::vec3 getPosition();

		void setHalfSize(const glm::vec3& h);
		void setHalfSize(const GPED::real x, GPED::real y, GPED::real z);
		void setXHalfSize(const GPED::real x);
		void setYHalfSize(const GPED::real y);
		void setZHalfSize(const GPED::real z);
		glm::vec3 getHalfSize();
	protected:
		glm::vec3 m_position; // center
		glm::vec3 m_halfExtents; // half size

		GPED::c3AABB m_fitAABB;
	};
}

#endif