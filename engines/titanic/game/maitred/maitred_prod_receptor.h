/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef TITANIC_MAITRED_PROD_RECEPTOR_H
#define TITANIC_MAITRED_PROD_RECEPTOR_H

#include "titanic/core/game_object.h"

namespace Titanic {

enum ProdSource { MAITRED_BODY = 0, MAITRED_LEGS = 1, MAITRED_BUTTOCKS = 2, MAITRED_GENERAL = 3 };

class CMaitreDProdReceptor : public CGameObject {
	DECLARE_MESSAGE_MAP;
	bool MouseButtonDownMsg(CMouseButtonDownMsg *msg);
	bool MouseMoveMsg(CMouseMoveMsg *msg);
	bool ProdMaitreDMsg(CProdMaitreDMsg *msg);
	bool DisableMaitreDProdReceptor(CDisableMaitreDProdReceptor *msg);
protected:
	ProdSource _prodSource;
	int _counter;
	bool _proddable;
public:
	CLASSDEF;
	CMaitreDProdReceptor() : CGameObject(),
		_prodSource(MAITRED_BODY), _counter(0), _proddable(true) {}

	/**
	 * Save the data for the class to file
	 */
	virtual void save(SimpleFile *file, int indent);

	/**
	 * Load the data for the class from file
	 */
	virtual void load(SimpleFile *file);
};

} // End of namespace Titanic

#endif /* TITANIC_MAITRED_PROD_RECEPTOR_H */
