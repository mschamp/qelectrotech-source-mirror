/*
	Copyright 2006-2023 The QElectroTech Team
	This file is part of QElectroTech.

	QElectroTech is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 2 of the License, or
	(at your option) any later version.

	QElectroTech is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with QElectroTech.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef CONDUCTORAUTONUMEROTATION_H
#define CONDUCTORAUTONUMEROTATION_H

#include "autoNum/assignvariables.h"

#include <QList>

class Diagram;
class Conductor;
class QUndoCommand;
class ConductorProperties;

/**
	@brief The ConductorAutoNumerotation class
*/
class ConductorAutoNumerotation
{
	public:
		//constructors & destructor
		ConductorAutoNumerotation (Conductor *conductor,
					   Diagram *diagram,
					   QUndoCommand *undo_parent = nullptr);

		//methods
		void        numerate       ();
		void        applyText      (const QString&);
		static void newProperties(Diagram *diagram,
					  ConductorProperties &cp,
					  autonum::sequentialNumbers &seq);

	private:
		//methods
		void numeratePotential ();
		void numerateNewConductor ();

		//attributes
		Diagram            *m_diagram;
		Conductor          *m_conductor;
		QList <Conductor *>  conductor_list;
		QUndoCommand       *m_parent_undo;
};

#endif // CONDUCTORAUTONUMEROTATION_H
