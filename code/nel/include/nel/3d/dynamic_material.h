// NeL - MMORPG Framework <http://dev.ryzom.com/projects/nel/>
// Copyright (C) 2010  Winch Gate Property Limited
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.


#ifndef DYN_MATERIAL_H
#define DYN_MATERIAL_H

#include "nel/misc/stream.h"
#include <string>
#include <vector>

namespace NL3D
{

	struct CDynMaterialProp
	{
		enum EPropertyType
		{
			Color,
			Vector4,
			Float,
			Double,
			Int,
			Uint,
			Matrix4,
			Texture
		};

		std::string prop;
		std::string label;
		uint8 type;
		std::string value;
	};

	class CDynMaterial : public NLMISC::IStreamable
	{
	public:
		CDynMaterial();
		~CDynMaterial();
		void serial( NLMISC::IStream &f );

		void addProperty( const CDynMaterialProp &prop );
		void removeProperty( const std::string &name );
		void changeProperty( const std::string &name, const CDynMaterialProp &prop );

	private:
		std::vector< CDynMaterialProp > properties;
	};
}

#endif


