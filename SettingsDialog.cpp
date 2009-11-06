/*
    Scan Tailor - Interactive post-processing tool for scanned pages.
    Copyright (C) 2007-2009  Joseph Artsimovich <joseph_a@mail.ru>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "SettingsDialog.h.moc"
#include "config.h"
#include <QSettings>
#include <QVariant>

SettingsDialog::SettingsDialog(QWidget* parent)
:	QDialog(parent)
{
	ui.setupUi(this);

	QSettings settings;

#ifdef ENABLE_OPENGL
	ui.use3DAcceleration->setChecked(
		settings.value("settings/use_3d_acceleration", false).toBool()
	);
#else
	ui.use3DAcceleration->setChecked(false);
	ui.use3DAcceleration->setEnabled(false);
	ui.use3DAcceleration->setToolTip(tr("Compiled without OpenGL support."));
#endif

	connect(ui.buttonBox, SIGNAL(accepted()), SLOT(commitChanges()));
}

SettingsDialog::~SettingsDialog()
{
}

void
SettingsDialog::commitChanges()
{
	QSettings settings;
#ifdef ENABLE_OPENGL
	settings.setValue("settings/use_3d_acceleration", ui.use3DAcceleration->isChecked());
#endif
}