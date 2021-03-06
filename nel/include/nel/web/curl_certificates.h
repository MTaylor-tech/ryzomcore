// Ryzom - MMORPG Framework <http://dev.ryzom.com/projects/ryzom/>
// Copyright (C) 2010  Winch Gate Property Limited
//
// This source file has been modified by the following contributors:
// Copyright (C) 2019  Jan BOON (Kaetemi) <jan.boon@kaetemi.be>
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

#ifndef CL_CURL_CERTIFICATES_HTML_H
#define CL_CURL_CERTIFICATES_HTML_H

#include "nel/misc/types_nl.h"

// forward declaration to avoid curl.h inclusion everywhere
typedef void CURL;

namespace NLWEB
{
	class CCurlCertificates
	{
	public:
		// allow to use custom PEM certificates
		static void addCertificateFile(const std::string &cert);

		// set all CURL options to use custom SSL context function
		static void useCertificates(CURL *curl);
	};

} // namespace
#endif

/* end of file */
