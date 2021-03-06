/*
#-----------------------------------------------------------------------------
# osm2pgsql - converts planet.osm file into PostgreSQL
# compatible output suitable to be rendered by mapnik
#-----------------------------------------------------------------------------
# Original Python implementation by Artem Pavlenko
# Re-implementation by Jon Burgess, Copyright 2006
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#-----------------------------------------------------------------------------
*/

#ifndef PARSE_PBF_H
#define PARSE_PBF_H

#include "parse.hpp"

#include "config.h"

#ifdef BUILD_READER_PBF
extern "C" {
#include "fileformat.pb-c.h"
#include "osmformat.pb-c.h"
}

class parse_pbf_t: public parse_t
{
public:
	parse_pbf_t(const int extra_attributes_, const bool bbox_, const boost::shared_ptr<reprojection>& projection_,
				const double minlon, const double minlat, const double maxlon, const double maxlat);
	virtual ~parse_pbf_t();
	virtual int streamFile(const char *filename, const int sanitize, osmdata_t *osmdata);
protected:
	parse_pbf_t();
	int processOsmDataNodes(struct osmdata_t *osmdata, PrimitiveGroup *group, StringTable *string_table, double lat_offset, double lon_offset, double granularity);
	int processOsmDataDenseNodes(struct osmdata_t *osmdata, PrimitiveGroup *group, StringTable *string_table, double lat_offset, double lon_offset, double granularity);
	int processOsmDataWays(struct osmdata_t *osmdata, PrimitiveGroup *group, StringTable *string_table);
	int processOsmDataRelations(struct osmdata_t *osmdata, PrimitiveGroup *group, StringTable *string_table);
	int processOsmData(struct osmdata_t *osmdata, void *data, size_t length);
};

#endif //BUILD_READER_PBF

#endif
