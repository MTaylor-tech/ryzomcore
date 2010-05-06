// Ryzom - MMORPG Framework <http://dev.ryzom.com/projects/ryzom/>
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

/* Copyright, 2001 Nevrax Ltd.
 *
 * This file is part of NEVRAX RYZOM.
 * NEVRAX RYZOM is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.

 * NEVRAX RYZOM is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with NEVRAX RYZOM; see the file COPYING. If not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 * MA 02111-1307, USA.
 */

#include "stdpch.h"

#include "nel/misc/debug.h"
#include "skills.h"
#include "nel/misc/string_conversion.h"

using namespace std;
using namespace NLMISC;

namespace SKILLS
{

static string UnknownString("Unknown");

	NL_BEGIN_STRING_CONVERSION_TABLE (ESkills)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SC)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAH)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAHB)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAHBE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAHBEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAHG)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAHGE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAHGEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAHH)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAHHE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAHHEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAHP)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAHPE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAHPEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAHS)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAHSE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAHSEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAHV)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAHVE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAHVEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAL)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCALB)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCALBE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCALBEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCALG)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCALGE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCALGEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCALP)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCALPE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCALPEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCALS)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCALSE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCALSEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCALV)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCALVE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCALVEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAMB)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAMBE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAMBEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAMG)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAMGE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAMGEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAMP)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAMPE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAMPEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAMS)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAMSE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAMSEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAMV)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAMVE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAMVEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCAS)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCASB)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCASBE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCASBEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCASS)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCASSE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCASSEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJ)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJAA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJAAE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJAAEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJB)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJBA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJBAE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJBAEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJD)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJDA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJDAE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJDAEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJEA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJEAE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJEAEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJP)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJPA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJPAE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJPAEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJR)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJRA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJRAE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCJRAEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1A)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1AE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1AEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1D)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1DE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1DEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1M)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1ME)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1MEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1P)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1PE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1PEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1S)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1SE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1SEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1T)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1TE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM1TEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM2)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM2A)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM2AE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM2AEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM2M)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM2ME)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM2MEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM2P)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM2PE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM2PEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM2S)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM2SE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCM2SEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCMC)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCMCA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCMCAE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCMCAEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCR)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCR1)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCR1P)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCR1PE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCR1PEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCR2)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCR2A)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCR2AE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCR2AEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCR2L)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCR2LE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCR2LEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCR2R)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCR2RE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SCR2REM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SF)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM1)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM1B)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM1BM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM1BMM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM1BS)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM1BSM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM1P)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM1PS)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM1PSM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM1S)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM1SA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM1SAM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM1SS)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM1SSM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM2)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM2B)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM2BM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM2BMM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM2P)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM2PP)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM2PPM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM2S)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM2SA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM2SAM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM2SS)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFM2SSM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFMC)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFMCA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFMCAD)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFMCADM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFMCAH)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFMCAHM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFR)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFR1)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFR1A)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFR1AP)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFR1APM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFR2)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFR2A)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFR2AA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFR2AAM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFR2AL)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFR2ALM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFR2AR)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SFR2ARM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SH)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHF)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFD)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFDA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFDAE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFDAEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFF)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFFA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFFAE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFFAEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFJ)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFJA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFJAE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFJAEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFL)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFLA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFLAE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFLAEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFP)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFPA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFPAE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SHFPAEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SMD)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SMDA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SMDAA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SMDAAE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SMDAAEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SMDH)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SMDHA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SMDHAE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SMDHAEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SMO)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SMOA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SMOAA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SMOAAE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SMOAAEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SMOE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SMOEA)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SMOEAE)
	  NL_STRING_CONVERSION_TABLE_ENTRY(SMOEAEM)
	  NL_STRING_CONVERSION_TABLE_ENTRY(unknown)
	NL_END_STRING_CONVERSION_TABLE(ESkills, SkillsConversion, unknown)


	ESkills toSkill( const std::string &str )
	{
		return SkillsConversion.fromString(str);
	}

	const std::string& toString( uint16 skill )
	{
		return SkillsConversion.toString((ESkills)skill);
	}


	const std::string& getSkillCategoryName( uint16 s )
	{
		return UnknownString;
	}

}; // SKILLS
