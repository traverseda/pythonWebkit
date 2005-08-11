/*
    Copyright (C) 2004, 2005 Nikolas Zimmermann <wildfox@kde.org>
				  2004, 2005 Rob Buis <buis@kde.org>

    This file is part of the KDE project

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#include "EntityReferenceImpl.h"
#include "EntityImpl.h"
#include "DocumentImpl.h"
#include "DocumentTypeImpl.h"
#include "NamedNodeMapImpl.h"
#include "DOMImplementationImpl.h"

using namespace KDOM;

EntityReferenceImpl::EntityReferenceImpl(DocumentImpl *doc, DOMStringImpl *name, bool expand) : NodeBaseImpl(doc)
{
	m_entityName = name;
	if(m_entityName)
		m_entityName->ref();

	if(expand && doc->doctype() && doc->parsing() == false)
	{
		NodeImpl *n = doc->doctype()->entities()->getNamedItem(name);
		if(n && n->nodeType() == ENTITY_NODE)
		{
			doc->setParsing(true);
			static_cast<EntityImpl *>(n)->cloneChildNodes(this, doc);
			doc->setParsing(false);
		}
	}
}

EntityReferenceImpl::~EntityReferenceImpl()
{
	if(m_entityName)
		m_entityName->deref();
}

DOMString EntityReferenceImpl::nodeName() const
{
	return DOMString(m_entityName);
}

unsigned short EntityReferenceImpl::nodeType() const
{
	return ENTITY_REFERENCE_NODE;
}

NodeImpl *EntityReferenceImpl::cloneNode(bool deep, DocumentImpl *doc) const
{
	EntityReferenceImpl *p = new EntityReferenceImpl(doc, m_entityName, false);

	if(deep)
	{
		bool oldMode = doc->parsing();
		doc->setParsing(true);
		cloneChildNodes(p, doc);
		doc->setParsing(oldMode);
	}

	return p;
}

bool EntityReferenceImpl::childTypeAllowed(unsigned short type) const
{
	switch(type)
	{
		case ELEMENT_NODE:
		case TEXT_NODE:
		case COMMENT_NODE:
		case PROCESSING_INSTRUCTION_NODE:
		case CDATA_SECTION_NODE:
		case ENTITY_REFERENCE_NODE:
			return true;
			break;
		default:
			return false;
	}
}

// vim:ts=4:noet
